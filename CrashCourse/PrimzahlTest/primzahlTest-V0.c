#include <stdio.h>

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
    while ( i < n && teilerGefunden == 0 ) { 
        if ( n % i == 0 ) {
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

