/* Ist b ein Teiler von a ? */
#include <stdio.h>
#define OK 0
#define ERROR 1

int main(void) {
    int b = 6;
    int a = 325;

    printf("Feste Zahlenwerte: b=%d, a=%d\n",b,a);

    while(a >= b) {
        a = a - b;
    }

    if (a == 0) {
        printf("b teilt a\n");
    } else {
        printf("b ist kein Teiler von a\n");
    }
    return 0;
}
