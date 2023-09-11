#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv)
{
    int *p = aligned_alloc(8, 8 * sizeof *p);
    if(!p)
    {
        printf("aligned allocation failed with err = %d\n", errno);
        return EXIT_FAILURE;
    }
    printf("8 bytes aligned address = %p\n", (void*) p);
    free(p);

    int *a = (int*) malloc(0);
    *a = 17;
    printf("size of a = %lu, address of a = %p, *a = %d\n", sizeof(a), a, *a);

    return EXIT_SUCCESS;
}