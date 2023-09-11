#include "header.h"

int complicated_1(int input) {
    int tmp = times_two(input);
    tmp = plus_five(tmp);
    return tmp;
}