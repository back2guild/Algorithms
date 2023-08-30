#include <stdio.h>
#include <string.h>
#include <assert.h>

#define typename(x) _Generic((x), \
                        int: "int", \
                        float: "float", \
                        Person: "Person", \
                        default: "other")

int main(int argc, char const *argv[])
{
    typedef struct person {
        char *fn;
        char *ln;
    } Person;
    Person p = {.fn = "Rahul", .ln = "Chaudhary"};
    assert(strcmp(typename(1), "int") == 0);
    //assert(strcmp(typename(p), "other") == 0);
    printf("typename(p) = %s\n", typename(p));
    return 0;
}
