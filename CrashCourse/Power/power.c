#include <stdio.h>
#define BASIS 3
#define OK 0

int power(int basis, int exponent);

int main() {
    int i;

    for (i = 0; i < 10; ++i) {
        printf("%d^%d = %d\n", BASIS, i, power(BASIS, i));
    }
    return OK;
} 


/* 
** Berechnet basis^exponent,
** exponent >= 0
*/
int power(int basis, int exponent) {
    int i, ergebnis;

    ergebnis = 1;
    for (i = 1; i <= exponent ; ++i) {
        ergebnis *= basis;
    }
    return ergebnis;
}

