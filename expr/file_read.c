#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_ssize_t.h>

#define FILENAME "netstat.log"
int main(int argc, char **argv)
{
    FILE *fp = fopen(FILENAME, "r");
    if(!fp) {
        perror("Failed to open file\n");
        return EXIT_FAILURE;
    }

    char *lineBuffer = NULL;
    size_t lineBuffSize = 0;
    ssize_t lineSize;
    int lineCount = 0;
    lineSize = getline(&lineBuffer, &lineBuffSize, fp);
    while (lineSize >= 0)
    {
        lineCount++;
        printf("%d  %s", lineCount, lineBuffer);
        lineSize = getline(&lineBuffer, &lineBuffSize, fp);
    }
    
    free(lineBuffer);
    lineBuffer = NULL;
    fclose(fp);
    return EXIT_SUCCESS;
}