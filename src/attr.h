
#ifndef _ATTR_H_
#define _ATTR_H_ 1
    #if !defined (PRINTFLIKE)
        #if defined (__GNUC__)
            #define PRINTFLIKE(n,m) __attribute__((format(printf,n,m)))
        #endif
    #endif
    
    // declare required libs
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdnoreturn.h>
    #include <stdlib.h>
    #include <string.h>

    void varmsg(int errnum, const char *fmt, va_list ap);
    noreturn void errmsg(int exitcode, int errnum, const char *fmt, ...) PRINTFLIKE(3, 4);
    void warnmsg(int errnum, const char *fmt, ...); 
#endif