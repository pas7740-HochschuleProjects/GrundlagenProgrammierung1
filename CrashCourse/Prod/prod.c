/*
 * Multipliziere die Zahlen von 1 - n
 * (AKA n!)
 * Datentyp int: wieviel Byte?
 */
#include <stdio.h>
#define OK 0

int main (void) {
    int n=10;     /* Multipliziere die ersten n Zahlen  */
    int prod=1;   /* Darin akkumulieren wir das Produkt */

    int i=1;      /* Laufvariable                      */
    while (i <= n) {
        prod *=  i;
        i++;
    }

    printf("Das Produkt der natuerlichen Zahlen 1 - %d ist %d\n",n,prod);

    return OK;
}
