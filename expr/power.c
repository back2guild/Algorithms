#include <stdlib.h>
#include <stdio.h>
#include <fenv.h>
#include <errno.h>
#include <math.h>

void exp1() {
    double pwr, sum = 0;
    int n, i;

    printf("\n1+4(3+3^2+3^3+3^4+...+3^N)=?\nEnter N : ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Invalid power N = %d\n", n);
        //return EXIT_FAILURE;
    }

    errno = 0;
    for(i = 0; i < n + 1; i++)
    {
        feclearexcept(FE_ALL_EXCEPT);
        pwr = powl(3,i);
        if(fetestexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW)) {
            perror("Math error");
        }

        sum = sum+i? pwr : 0;
        printf("N = %d\tS = %g\n", i, 1+4*sum);
    }
}

void exp3() {
    printf("%f\n",1/.1);
    printf("%19.17f\n",1/.1);
}

int main(int argc, char **argv) {
    char *p;
    long num = strtol(argv[1], &p, 10);
    printf("%ld\n", num);
    printf("%s\n", p);
    exp3();
    return 0;
}