// Demonstrate that fgets/sscanf does not suffer from buffer overwrite problems.
// However, the input buffer should be cleared if you do multiple reads.
//
// Disable CLEAN_BUFFER and enter
// on windows (MinGW)
//       String with length of at least 11 characters
// on linux
//       String with length of at least 17 characters
//       On linux the gcc compiler uses 16 byte alignemnet.
//
// Then define CLEAN_BUFFER and repeat the test
//
#include<stdio.h>

#define PUFFERGROESSE 10
//#define CLEAN_BUFFER

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
    char stringPufferIn[PUFFERGROESSE];
    int i;

    while(1) {
        printf("Bitte String eingeben:"); fflush(stdout);
        if(fgets(stringPufferIn,PUFFERGROESSE,stdin) == NULL) {
            printf("Fehler beim Lesen\n");
            return ERROR;
        }

        i = stringLaenge(stringPufferIn);

#ifdef CLEAN_BUFFER
        if ( stringPufferIn[i] != '\n') {
            // Das letzte Nutzzeichen im Puffer ist nicht '\n'.
            // Es gibt also noch mehr Zeichen im Eingabekanal.
            // Input Puffer loeschen
            while(fgetc(stdin) != '\n');
        }
#endif
        if ( stringPufferIn[i] == '\n') {
            stringPufferIn[i] = '\0';
        } 
        printf("Der String %s hat die Laenge %d\n",stringPufferIn,i);

        if (i>=3 
                && stringPufferIn[0] == 'E'
                && stringPufferIn[1] == 'n'
                && stringPufferIn[2] == 'd'
                && stringPufferIn[3] == 'e'
           ){
            break;
        }

    }
    printf("Good Bye\n");
    return OK;
}
