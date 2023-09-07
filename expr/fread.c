#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    #if defined (__APPLE__) && defined(__MACH__)
        printf("%s\n", "hello world!");
    #endif
    return EXIT_SUCCESS;
}