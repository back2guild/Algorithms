#include "header.h"

int main(int argc, char **argv) {
  int start = 3;
  int intermediate = complicated_1(start);
  printf("First result is %d\n", intermediate);
  intermediate = complicated_2(start);
  printf("Second result is %d\n", intermediate);
  return 0;
}