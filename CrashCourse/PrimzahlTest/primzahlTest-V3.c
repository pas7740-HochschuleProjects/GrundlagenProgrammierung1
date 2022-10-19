#include <stdio.h>
#include <math.h>

int main() {
    int n;              /* zu testende Zahl              */
    int i;              /* Laufvariable der Schleife     */
    int res;            /* fuer Resultat scanf           */
    int teilerGefunden; /* Flag fuer Abbruch in Schleife */

    printf("Bitte Zahl eingeben: "); fflush(stdout);
    res = scanf("%d", &n) ;
    if (res != 1) {
        printf("Fehlerhafte Eingabe der Zahl!");
        return 1; /* 0: ok, 1: Fehler */
    }

    i = 2;
    teilerGefunden = 0; /* Flag fuer Abbruch */
    while ( i <= sqrt(n) && teilerGefunden == 0 ) { 
        int a;  /* Hilfsvariable fuer Division */
        { /* i teilt n mit Rest 0 ? */
            a = n;  /* a wird veraendert, nicht n nehmen */
            while (a >= i) {
                a = a - i;
            }
            /* Rest ist in a */
            printf("n=%d div %d gibt rest = %d\n",n,i,a);
        }
        if ( a == 0 ) {
            teilerGefunden = 1;
        } else {
            i = i + 1;
        }
    }

    if (teilerGefunden == 0) {
        printf("Kein Teiler gefunden, %d ist Primzahl\n", n);
    } else {
        printf("%d teilt %d, also keine Primzahl\n",i,n);
    }

    return 0; /* 0: ok, 1: Fehler */
}

