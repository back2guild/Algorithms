#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

noreturn void func() {
    printf("Inside func with noreturn\n");
    // return NULL;
    exit(0);
}

int return_something() {
    printf("I am suppoed to return something\n");
}

void modify_const_int()
{
    const int f = 10;
    int const *ptr = &f;
    printf("*ptr = %d\n", *ptr);
    const int b = 30;
    ptr = &b;
    printf("*ptr = %d\n", *ptr);
}

void divide_by_zero()
{
    printf("1/0 = %f\n",1/0);
}

int main(int argc, char **argv)
{
    modify_const_int();
    int ret = return_something();
    printf("ret = %d\n",ret);
    //free(&ret);
    //ret = return_something();
    divide_by_zero();
    func();
    return 0;
}