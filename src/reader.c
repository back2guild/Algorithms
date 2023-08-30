#include "reader.h"

char* read_file(char* filename, char* buffer,  const unsigned int BUFFER_SIZE)
{
    if(filename)
    {
        unsigned int current_size = BUFFER_SIZE;
        if(buffer != NULL) {
            free(buffer);
            buffer = NULL;
        }
        buffer = (char*) malloc(current_size * sizeof(char));
        memset(buffer,'\0',current_size);
        int c;
        FILE *f = fopen(filename,"r");
        unsigned int count = 0;
        while((c = fgetc(f)) != EOF)
        {
            if(count < current_size)
            {
                *(buffer + count) = (char) c;
            }
            else {
                current_size += BUFFER_SIZE;
                buffer = (char*) realloc(buffer, current_size);
                if(buffer)
                {
                    *(buffer + count) = (char) c;
                }
            }
            count++;
        }
        fclose(f);
    }
    return buffer;
}