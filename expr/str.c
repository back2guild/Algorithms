#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return EXIT_FAILURE;
    }
    char *text = argv[1];
    char key = 'i';

    if(text != NULL)
    {
        char *ptr = strchr(text, key);
        if(ptr != NULL)
        {
            printf("First occurance of %c in %s is %d\n", key, text, ptr[1]);
        }
    }
    return 0;
}