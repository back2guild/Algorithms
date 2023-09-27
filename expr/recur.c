#include <stdio.h>

void process(size_t t)
{
    if(t == 0)
        return;
    else {
        printf("%lu\t", t);
        process(--t);
    }
}

int main(int argc, char const *argv[])
{
    process(10000000);
    printf("\n");
    return 0;
}
