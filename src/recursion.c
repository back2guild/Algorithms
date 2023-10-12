#include "recurson.h"


size_t factorial(int num) {
    if(num < 1) {
        return;
    }
    else if(num == 1) {
        return 1;
    }
    else {
        return num * factorial(num - 1);
    }
}
