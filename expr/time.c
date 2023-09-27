#include <stdio.h>
#include <time.h>
#include <stdint.h>


int main(int argc, char const *argv[]) {
    time_t t = 0x7FFFFFFF;
    //time(&t);
    printf("%s\n", asctime(gmtime(&t)));
    return 0;
}
