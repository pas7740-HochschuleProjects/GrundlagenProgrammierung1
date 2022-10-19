#include<stdio.h>

#define ERROR 1
#define OK 0

int main(void) {
    int lowerBound;
    int upperBound;
    int i;

    // Einlesen
    printf("Bitte Untergrenze und Obergrenze eingeben: "); fflush(stdout);
    if ( scanf("%d %d",&lowerBound, &upperBound) != 2) {
        printf("Fehler beim Einlesen\n");
        return ERROR;
    }
    // Eingabepuffer leeren hier nicht noetig, da wir nur einmal lesen.
    // Das muss man nur machen, wenn man in unterschiedlichen Anweisungen
    // mehrmals von Eingabe lesen will!
    //
    // while (getchar() != '\n');

    for (i = lowerBound; i <= upperBound; i++) {
        // if( i % 2 ) {  // das ist kuerzer aber schwerer zu lesen!
        if( i % 2 != 0 ) {
            printf("%10d ist ungerade\n",i);
        } else {
            printf("%10d ist   gerade\n",i);
        }   
    }
    return OK;
}
