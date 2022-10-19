/*
** Strings von Konsole lesen
** Versuche Eingabe 0123456789012
** Versuche Eingabe 01234567890123
** Versuche Eingabe 012345678901234
*/

#include<stdio.h>
#include<string.h>

// Fuer Debug-Ausgabe setzen
#undef DEBUG
#define DEBUG

// Wir definieren Fehlercodes als Makros (C-Praeprozessor)
#define OK 0
#define ERROR 1

// Grenzen fuer Definition von Feldern und Schleifen
#define MAX_BUFF_SIZE 15
#define FORMAT_STRING 

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

int main(void) {
    char buffer[MAX_BUFF_SIZE];

    printf("Eingabe: > ");
    fflush(stdout);
    if(readALine(buffer,MAX_BUFF_SIZE)) {
        printf("Fehler beim Lesen\n");
        return ERROR;
    }

    // Was wurde eingegeben?
    // Falls Puffer voll, dann kein \n am Ende des Puffers
    // Falls noch Platz im Puffer, dann ist \n am Ende des Puffers
    printf("Eingabe=%s\n",buffer);

    return OK;
}
