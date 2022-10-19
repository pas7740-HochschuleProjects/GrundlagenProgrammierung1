/* Fuehre ganzzahlige Division a/b aus und berechne Ergebnis sowie Rest r */
#include <stdio.h>
#define OK 0
#define ERROR 1

int main(void) {
    int a = 328;      /* Eingabe koennen wir noch nicht */
    int b = 6;
    printf("Feste Zahlenwerte: a=%d, b=%d\n",a,b);

    while(a >= b) {
        a = a - b;
    }
    /* Rest steht in a */
    printf("rest %d\n",a);
    return OK;
}
