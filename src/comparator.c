#include "comparator.h"

int compareAsInt(void *p1, void *p2) {
    if(NULL != p1 && NULL != p2)
    {
        int *i1= (int*) p1;
        int *i2= (int*) p2;
        return ((*i1 > *i2) ? 1 :((*i1 < *i2)? -1: 0));
    }
    return INVALID;
}