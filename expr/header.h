#ifndef _HEADER_H_
#define _HEADER_H_ 1
    #include <stdio.h>

    int complicated_1(int);
    int complicated_2(int);
    
    inline int times_two(int input) {
        return input * 2;
    }

    inline int plus_five(int input) {
        return input + 5;
    }
#endif