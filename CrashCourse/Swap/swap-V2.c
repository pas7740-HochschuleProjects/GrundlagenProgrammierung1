/*
 * Demonstrate call by reference semantics of C
 */

#include <stdio.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int i1=1;
    int i2=2;
    printf("Before swap\n");
    printf("i1: %d\n",i1);
    printf("i2: %d\n",i2);

    swap(&i1,&i2);

    printf("After swap\n");
    printf("i1: %d\n",i1);
    printf("i2: %d\n",i2);

    return 0;
}
