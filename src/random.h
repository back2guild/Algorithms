#ifndef _RANDOM_H_
#define _RANDOM_H_ 1
    #include "common.h"
    #include <limits.h>
    #include <sys/random.h>

    long long get_random_number();
    long random_unit(void);
#endif