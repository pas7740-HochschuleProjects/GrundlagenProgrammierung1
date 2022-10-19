// Robustere Implementierung durch Verwendung von fgets und sscanf
#include <stdio.h>
#include <string.h>
#define OK    0
#define ERROR 1
#define MAX_BUFF_SIZE 10
#undef DEBUG
#define DEBUG

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
                printf("Laenge des gelesenen Strings: %d\n",len);
                printf("Der Code des letzten Nutzzeichens ist: %d\n",buffer[strlen(buffer) -1]);
                printf("Der Code des letzten Zeichens ist: %d\n",buffer[strlen(buffer)]);
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

int main() {
    int fhwert, startwert,endwert, schrittweite;
    char buffer[MAX_BUFF_SIZE];

    printf("Startwert="); fflush(stdout);
    if (readALine(buffer,MAX_BUFF_SIZE) || sscanf(buffer,"%d", &startwert) != 1) {
        printf("Fehlerhafte Eingabe des Startwerts!");
        return ERROR;
    }

    printf("Endwert="); fflush(stdout);
    if (readALine(buffer,MAX_BUFF_SIZE) || sscanf(buffer,"%d", &endwert) != 1) {
        printf("Fehlerhafte Eingabe des Endwerts!");
        return ERROR;
    }

    printf("Schrittweite="); fflush(stdout);
    if (readALine(buffer,MAX_BUFF_SIZE) || sscanf(buffer,"%d", &schrittweite) != 1) {
        printf("Fehlerhafte Eingabe der Schrittweite!");
        return ERROR;
    }

    printf("Startwert=%d, Endwert=%d, Schrittweite=%d\n",startwert,endwert,schrittweite);
    printf("Grad Fahrenheit\tGrad Celsius\n");
    for (fhwert = startwert; fhwert <= endwert;  
            fhwert = fhwert + schrittweite) {
        printf("%10d\t%7.1f\n", fhwert, (5.0/9.0)*(fhwert-32));
    }
    return OK;
}
