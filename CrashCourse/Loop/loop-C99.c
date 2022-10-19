#include<stdio.h>
#define OK 0

int add(int a, int b) {
    return a+b;
}

int main() {
    int j; 
    // Ab C99 darf man Schleifenvariable in der Schleifenanweisung definieren.
    // Vergleiche: Java und C++
    for (int i = 0; i<10; i++) {
        j = i + 10;
        printf("i=%d j=%d i+j=%d\n",i,j,add(i,j));
    }
    return OK;
}
