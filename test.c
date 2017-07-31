
#include <stdio.h>
#include <stdlib.h>
int f(int n);


int main (){

    int a = 5;
    int *p;
    p = &a;
    //*p = *p + 1;
    printf("%p\n", p);
    p++;
    printf("%p\n", p);
    *p = *p + 1;
    printf("pointer =  %d\n", *p);
    a++;

    printf("%d\n", a);
    return 0;
}
