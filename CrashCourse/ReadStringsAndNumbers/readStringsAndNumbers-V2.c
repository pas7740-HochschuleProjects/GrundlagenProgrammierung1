/*
** Strings und Zahlen von Konsole lesen
** Versuche Eingabe 012345678901 12 
** Versuche Eingabe 0123456789012 12 
**
** \n und \0 muessen auch gespeichert werden
*/

#include<stdio.h>
#include<string.h>

// Fuer Debug-Ausgabe setzen
#undef DEBUG
//#define DEBUG

// Wir definieren Fehlercodes als Makros (C-Praeprozessor)
#define OK 0
#define ERROR 1

// Grenzen fuer Definition von Feldern und Schleifen
#define MAX_BUFF_SIZE 15

int readALine(char *buffer, int bufsize) {
    int len;
    char* res;
    // Puffer fasst maximal bufsize Zeichen
    // '\n' verbraucht Platz und fgets fuegt terminales '\0' an.
    // Daher maximal bufsize-2 Zeichen fuer eigentliche Eingabe.
    res = fgets(buffer,bufsize,stdin);
    if (res != NULL) {
        // Wir haben erfolgreich den Puffer buffer gefuellt
        len = strlen(buffer);
        if (len > 0 && buffer[strlen(buffer) -1] != '\n') {
            // Die Eingabezeile war noch nicht zu Ende
            // Rest im IO Puffer loeschen
#ifdef DEBUG
            {
                int i = 0;
                printf("\n");
                printf("Pufferlaenge = %d\n",bufsize);
                printf("Laenge des gelesenen Strings: %d\n",len);
                printf("Das letzte Nutzzeichen ist: %c (code = %d)\n",
                    buffer[strlen(buffer) -1],buffer[strlen(buffer) -1]);

                do i++; while (fgetc(stdin) != '\n');
                printf("Habe %d Restzeichen aus Eingabe Strom geloescht\n",i);
            }
#else
            while (fgetc(stdin) != '\n');
#endif
        }
    }
    return res == NULL;
}

int main(void) {
    char buffer[MAX_BUFF_SIZE];
    char wort[MAX_BUFF_SIZE]; // String Puffer mindestens so gross wie Eingabepuffer
    int  izahl;

    printf("Eingabe: String Zahl > ");
    fflush(stdout);
    if(readALine(buffer,MAX_BUFF_SIZE)) {
        printf("Fehler beim Lesen\n");
        return ERROR;
    }

    // Es wurde etwas eingegeben. Hat es das richtige Format?
    if(sscanf(buffer,"%s %d",wort,&izahl) != 2) { // keine Beschraenkung fuer String hier!
        printf("Eingabe hat falsches Format\n");
        return ERROR;
    } else {
        printf("Wort=%s Zahl=%d\n",wort,izahl);
        return OK;
    }

}
