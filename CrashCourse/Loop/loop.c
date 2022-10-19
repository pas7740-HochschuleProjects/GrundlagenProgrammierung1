#include<stdio.h>
#define OK 0

int add(int a, int b) {
    return a+b;
}

int main() {
    int i,j; 
    for (i = 0; i<10; i++) {
        j = i + 10;
        printf("i=%d j=%d i+j=%d\n",i,j,add(i,j));
    }
    return OK;
}
