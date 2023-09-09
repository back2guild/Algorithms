#include "common.h"
#include <sys/utsname.h>

void bit_pattern(int num) {
  int i, x, word;
  unsigned int mask = 1;

  word = CHAR_BIT * sizeof(int);
  mask = mask >> (word - 1);
  for (i = 0; i <= word; i++) {
    x = (num & mask) ? 1 : 0;
    printf("%d", x);
    mask >>= 1;
  }
}

void get_sys_info(void) {
  struct utsname a;
  if (uname(&a) == 0) {
    printf("machine = %s\n", a.machine);
    printf("machine = %s\n", a.nodename);
    printf("machine = %s\n", a.release);
    printf("machine = %s\n", a.sysname);
    printf("machine = %s\n", a.version);
  }
}

void create_random_list(unsigned long long *input, unsigned long lower, unsigned long long upper, unsigned long long size)
{
    if(input)
    {
        srand(time(0));
        for(unsigned long long i = size; i > 0 ; i--)
        {
           *(input + i) = ((rand() % (upper - lower + 1)) + lower);
        }
    }
}