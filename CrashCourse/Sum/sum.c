/*
 * Summiere die Zahlen von 1 - n
 *
 */
#include <stdio.h>
#define OK 0

int main (void) {
    int n=100;   /* Summiere die ersten n Zahlen     */
    int sum=0;   /* Darin akkumulieren wir die Summe */

    int i=0;       /* Laufvariable                   */
    while (i <= n) {
        sum = sum + i;
        i = i + 1;
    }

    printf("Die Summe der natuerlichen Zahlen 1 - %d ist %d\n",n,sum);
    return OK;
}
