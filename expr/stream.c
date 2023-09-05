#include <stdio.h>
#include <stdlib.h>

void display_stream(FILE *stream)
{
    int c;
    while((c = getc(stream)) != EOF)
    {
        putchar(c);
    }
}


int main(int argc, char **argv)
{
    FILE *fp = NULL;
    if(argc != 2)
    {
        perror("insufficient arguments");
        return EXIT_FAILURE;
    }

    if((fp = popen(argv[1], "r")) == NULL)
    {
        perror("failed to open process\n");
        return EXIT_FAILURE;
    }

    display_stream(fp);
    if(fp)
        pclose(fp);
    return EXIT_SUCCESS;
}