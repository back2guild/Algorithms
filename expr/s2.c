#include "header.h"

int complicated_2(int input) {
    int tmp = plus_five(input);
    tmp = times_two(tmp);
    return tmp;
}