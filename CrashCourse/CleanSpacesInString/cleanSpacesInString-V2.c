// Demonstrate fix of overflow due to usage of function
//       char *fgets(char *s, int size, FILE* stream)
//
// On windows (MinGW)
//  enter a string with length of at least 11 characters
//  Example: 012345  89MNOPQR
// On linux
//  enter a string with length of at least 17 characters
//  On linux gcc uses alignement to 16 Byte boundaries.
//  Example: 012345  89012345MNOPQR

#include<stdio.h>

#define PUFFERGROESSE 10

#define OK 0
#define ERROR 1

int main(void) {
    char stringPufferIn0[PUFFERGROESSE];
    char stringPufferIn1[PUFFERGROESSE];
    char stringPufferIn2[PUFFERGROESSE];
    char stringPufferOut[PUFFERGROESSE];
    int i, j;

    for(i=0; i< PUFFERGROESSE-1; i++){
        stringPufferIn0[i] = 65 + i;
        stringPufferIn2[i] = 97 + i;
    }
    // Alle Puffer sauber mit '\0' terminieren, damit String-Funktionen
    // korrekt funktionieren.
    stringPufferIn0[PUFFERGROESSE-1] = '\0';
    stringPufferIn2[PUFFERGROESSE-1] = '\0';
    stringPufferIn1[0] = '\0';
    stringPufferOut[0] = '\0';

    printf("%p:stringPufferIn0=%s\n",stringPufferIn0,stringPufferIn0);
    printf("%p:stringPufferIn1=%s\n",stringPufferIn1,stringPufferIn1);
    printf("%p:stringPufferIn2=%s\n",stringPufferIn2,stringPufferIn2);
    printf("%p:stringPufferOut=%s\n",stringPufferOut,stringPufferOut);
    printf("\n");

    printf("Bitte String eingeben:"); fflush(stdout);
    if(fgets(stringPufferIn1,PUFFERGROESSE,stdin) == NULL) {
        printf("Fehler beim Lesen\n");
        return ERROR;
    }

    /* Kopieren und dabei Leerzeichen entfernen */
    i=0;  j=0;
    while(stringPufferIn1[i] != '\0') {
        if(stringPufferIn1[i] != ' ') {
            stringPufferOut[j] = stringPufferIn1[i];
            j++;
        }
        i++;
    }
    /* Terminate string in output buffer */
    stringPufferOut[j] = '\0';
    printf("Der bereinigte String:%s\n",stringPufferOut);

    printf("\n");
    printf("%p:stringPufferIn0=%s\n",stringPufferIn0,stringPufferIn0);
    printf("%p:stringPufferIn1=%s\n",stringPufferIn1,stringPufferIn1);
    printf("%p:stringPufferIn2=%s\n",stringPufferIn2,stringPufferIn2);
    printf("%p:stringPufferOut=%s\n",stringPufferOut,stringPufferOut);
    printf("\n");

    return OK;
}
