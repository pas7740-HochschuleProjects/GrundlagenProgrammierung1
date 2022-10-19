/* Fuehre ganzzahlige Division a/b aus und berechne Ergebnis sowie Rest r */
/* Wir moechten am Schluss die Aufgabenstelung auf Konsole ausgeben       */
/* Daher Hilfsvariablen a_merk und div                                    */
#include <stdio.h>
#define OK 0
#define ERROR 1

int main(void) {
    int a = 328;      /* Eingabe koennen wir noch nicht */
    int b = 6;

    printf("Feste Zahlenwerte: a=%d, b=%d\n",a,b);

    int a_merk, div;  /* Hilfsvariablen */

    a_merk = a;       /* Wir merken uns das urspruengliche a */
    div=0;            /* div baut Ergebnis der Division auf */
    while(a >= b) {
        a = a - b;
        div++;
    }
    /* Rest der Division steht in a */
    printf("%d div %d = %d rest %d: \n",a_merk,b,div,a);

    return OK;
}
