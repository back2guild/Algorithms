#include <stdio.h>

int main(int argc, char const *argv[])
{
    #if defined(__STDC_NO_THREADS__)
        printf("Threads are not suported\n");
    #else
        printf("Threads are supported\n");
    #endif
    return 0;
}
