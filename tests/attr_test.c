#include "../src/attr.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 100

int main(int argc, char **argv) {
    if(argc != 2 && argv != NULL)
    {
        return EXIT_FAILURE;
    }

    const char *fn = argv[1];
    char BUFFER[BUFSIZE];
    int fd;
    if((fd = open(fn, O_RDONLY)) == -1)
    {
        errmsg(EXIT_FAILURE, errno, "cannot open %s", fn);
    }
    if(read(fd,BUFFER, sizeof(BUFFER)) != sizeof(BUFFER))
    {
        errmsg(EXIT_FAILURE, errno, "cannot read %zu bytes from %s", sizeof(BUFFER), fn);
    }
    if(close(fd) == -1)
    {
        warnmsg(errno, "can not close file %s", fn);
    }
    return EXIT_SUCCESS;
}