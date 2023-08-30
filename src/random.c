#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int get_random_number(const int low, const int high)
{
    srand(time(NULL));
    int result = (rand() % (high - low)) + low;
    return result;
}

unsigned int random_unit()
{
    srandom(time(NULL));
    return random();
}