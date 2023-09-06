#include <stdio.h>

enum Op
{
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/'
};


int add (int a, int b) {
    return a+b;
}

int sub (int a, int b) {
    return a-b;
}

int mul (int a, int b) {
    return a*b;
}

int div (int a, int b) {
    return a/b;
}

int (*get_math(enum Op op)) (int, int) {
    switch (op)
    {
    case '+':
        return &add;
    case '-':
        return &sub;
    case '*':
        return &mul;
    case '/':
        return &div;
    default:
        break;
    }
}

int main(int argc, char const *argv[])
{
    int a = 1, b =2, c;

    int (*ops)(int, int);
    ops = get_math(ADD);
    c = ops(a,b);
    printf("a = %d, b = %d, c = %d\n",a,b,c);
    ops = get_math(SUB);
    c = ops(a,b);
    printf("a = %d, b = %d, c = %d\n",a,b,c);
    ops = get_math(MUL);
    c = ops(a,b);
    printf("a = %d, b = %d, c = %d\n",a,b,c);
    ops = get_math(DIV);
    c = ops(a,b);
    printf("a = %d, b = %d, c = %d\n",a,b,c);
    return 0;
}
