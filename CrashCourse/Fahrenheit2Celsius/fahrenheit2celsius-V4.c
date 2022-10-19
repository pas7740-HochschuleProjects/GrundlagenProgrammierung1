/* Drucke Umrechnungstabelle von Fahrenheit nach Celsius */
/* Variablen sind float                                  */

#include <stdio.h>
#define OK 0

int main() {
    float fahrenheitWert;
    fahrenheitWert = .0;

    printf("Grad Fahrenheit\tGrad Celsius\n");
    while (fahrenheitWert <= 300) {
        float celsiusWert;
        /* Achtung: Zahlformat                         */
        /* 5/9 ergibt ganzzahlige Rechnung             */
        celsiusWert = 5/9.0 * (fahrenheitWert - 32);

        printf("%10.2f\t%10.2f\n", fahrenheitWert,celsiusWert);
        fahrenheitWert = fahrenheitWert + 20;
    }
    return OK;
}
