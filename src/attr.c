#include "attr.h"

void varmsg(int errnum, const char *fmt, va_list ap)
{
    if(fmt)
        vfprintf(stderr, fmt, ap);
    if(errnum != 0)
        fprintf(stderr, " : %s", strerror(errnum));
    putc('\n',  stderr);
}

noreturn void errmsg(int exitcode, int errnum, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    varmsg(errnum, fmt, ap);
    va_end(ap);
    exit(exitcode);
}
    
void warnmsg(int errnum, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    varmsg(errnum, fmt, ap);
    va_end(ap);
}