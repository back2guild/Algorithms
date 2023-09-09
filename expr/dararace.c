#include <stdio.h>
#include <stdlib.h>

void fn() {
    printf("function = %s, %d\n",__FUNCTION__,__STDC_VERSION__);
}

int main() {
    fn();
    char *s = NULL;
    int i = 42;
    printf("%s\n", s);
    i = i++;
    printf("i = %d\n",i);

    int a = i++ + ++i;
    printf("%d\n",a);

    int *d = (int*) malloc(sizeof(int));
    *d = 9;
    printf("address of d = %p , value of d = %d\n",d, *d);
    free(d);
    d = NULL;
    //printf("address of d = %p , value of d = %d\n",d, *d);
    //free(d);
    //printf("address of d = %p , value of d = %d\n",d, *d);
    return 0;
}