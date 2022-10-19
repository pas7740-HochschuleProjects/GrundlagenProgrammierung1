/*
 * Demonstrate call by reference semantics of C
 */

#include <stdio.h>

void swap(int* a, int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    printf("In swap\n");
    printf(" *a: %p at %p\n",a,&a);
    printf(" *b: %p at %p\n",b,&b);
    printf("tmp: %d at %p\n",tmp,&tmp);
}

int main()
{
    int i1=1;
    int i2=2;
    printf("Before swap\n");
    printf("i1: %d at %p\n",i1,&i1);
    printf("i2: %d at %p\n",i2,&i2);

    swap(&i1,&i2);

    printf("After swap\n");
    printf("i1: %d at %p\n",i1,&i1);
    printf("i2: %d at %p\n",i2,&i2);

    return 0;
}
