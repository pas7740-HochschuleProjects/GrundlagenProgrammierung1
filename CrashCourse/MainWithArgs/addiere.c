#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERROR 1

int main (int argc, char * argv[]) {
    if (argc != 3) {
        printf("Bitte 2 Zahlen eingeben:\n");
        printf("Beispiel:  %s 2 3 \n", argv[0]);
        return ERROR;
    }
    printf("%s + %s = %d \n", argv[1], argv[2], atoi(argv[1]) + atoi(argv[2]) );
    return OK;
}

