// Robustere Implementierung durch leeren des Puffers nach scanf
//
// Note:
// fflush(stdout) wichtig: das zeigt Demo unter rxvt.exe
// fflush(stdin): Wirkung im C-Standard nicht definiert!!
//                Daher besser mit while(getchar() != '\n');
//                Auf den meisten Platformen loescht fflush(stdin) den Eingabepuffer
//
#include <stdio.h>
#define OK    0
#define ERROR 1
int main() {
    int fhwert, startwert,endwert, schrittweite;

    printf("Startwert=");
    fflush(stdout);
    if (scanf("%d", &startwert) != 1) {
        printf("Fehlerhafte Eingabe des Startwerts!");
        return ERROR;
    }
    while(getchar() != '\n'); // Eingabepuffer leeren

    printf("Endwert=");
    fflush(stdout);
    if (scanf("%d", &endwert) != 1) {
        printf("Fehlerhafte Eingabe des Endwerts!");
        return ERROR;
    }
    while(getchar() != '\n'); // Eingabepuffer leeren

    printf("Schrittweite=");
    fflush(stdout);
    if (scanf("%d", &schrittweite) != 1) {
        printf("Fehlerhafte Eingabe der Schrittweite!");
        return ERROR;
    }
    while(getchar() != '\n'); // Eingabepuffer leeren

    printf("Startwert=%d, Endwert=%d, Schrittweite=%d\n",startwert,endwert,schrittweite);
    printf("Grad Fahrenheit\tGrad Celsius\n");
    for (fhwert = startwert; fhwert <= endwert;  
            fhwert = fhwert + schrittweite) {
        printf("%10d\t%7.1f\n", fhwert, (5.0/9.0)*(fhwert-32));
    }
    return OK;
}
