// Demonstrate buffer overwrite by scanf
// On windows (MinGW)
//  enter a string without spaces and a length of at least 11 characters
// On linux
//  enter a string without spaces and a length of at least 17 characters.
//  On linux gcc uses alignement to 16 byte boundaries.
#include<stdio.h>

#define PUFFERGROESSE 10

#define OK 0
#define ERROR 1

int stringLaenge(char string[]) {
    int i = 0;
    while(string[i] != '\0' && string[i] != '\n') {
        i++;
    }   
    return i;
}

int main(void) {
    char stringPufferIn0[PUFFERGROESSE];
    char stringPufferIn1[PUFFERGROESSE];
    char stringPufferIn2[PUFFERGROESSE];
    int i;

    for(i=0; i< PUFFERGROESSE-1; i++){
        stringPufferIn0[i] = 65 + i;
        stringPufferIn2[i] = 97 + i;
    }
    stringPufferIn0[PUFFERGROESSE-1] = '\0';
    stringPufferIn2[PUFFERGROESSE-1] = '\0';
    stringPufferIn1[0] = '\0';

    printf("%p: stringPufferIn0=%s\n",stringPufferIn0,stringPufferIn0);
    printf("%p: stringPufferIn1=%s\n",stringPufferIn1,stringPufferIn1);
    printf("%p: stringPufferIn2=%s\n",stringPufferIn2,stringPufferIn2);
    printf("\n");

    while(1) {
        printf("Bitte String eingeben:"); fflush(stdout);
        if(scanf("%s",stringPufferIn1) != 1) {
            printf("Fehler beim Lesen\n");
            return ERROR;
        }
        while(getchar() != '\n'); // Input Puffer leeren

        // Laenge berechnen
        i = stringLaenge(stringPufferIn1);
        printf("Der String %s hat die Laenge %d\n",stringPufferIn1,i);

        printf("%p: stringPufferIn0=%s\n",stringPufferIn0,stringPufferIn0);
        printf("%p: stringPufferIn1=%s\n",stringPufferIn1,stringPufferIn1);
        printf("%p: stringPufferIn2=%s\n",stringPufferIn2,stringPufferIn2);
        printf("\n");

        if (i>=3 
                && stringPufferIn1[0] == 'E'
                && stringPufferIn1[1] == 'n'
                && stringPufferIn1[2] == 'd'
                && stringPufferIn1[3] == 'e'
           ){
            break;
        }
    }
    printf("Good Bye\n");
    return OK;
}
