#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int get_random_number(const int low, const int high)
{
    srand(time(NULL));
    int result = (rand() % (high - low)) + low;
    return result;
}

unsigned int random_unit(unsigned int limit)
{
    srandom(time(NULL));
    printf("random = %ld\n", random());
}

int main(int argc, char const *argv[])
{
    int result =  get_random_number(1,100);
    random_unit(1);
    printf("random = %d\n", result);
    return 0;
}