// Nutzung von sizeof fuer Arrays
// Vorsicht!
//
// Fazit:
// nur in dem Block, in dem das Array definiert wird, liefert sizeof(Array-Name) die Anzahl
// der fuer das ganze Array benoetigen Bytes.
// Sonst immer nur den Speicherbedarf fuer den Pointer, der auf das Array zeigt.
// Insbesondere also immer in Funktionen, die ein Array als Parameter uebergeben bekommen.

#include <stdio.h>
#define OK 0

void druckeSizeOfArray(int a[], char* name) {
    printf("in druckeSizeofArray %s:%d\n",name,(int) sizeof(a));
}

void druckeSizeOfArrayPtr(int *a, char* name) {
    printf("in druckeSizeofArrayPtr %s:%d\n",name,(int) sizeof(a));
}

int main(void) {
    int a1[3] = {1,2,3};
    int a2[]  = {1,2,3};
    int a3[3];
    int *a4 = a3;

    a3[0] = 1;
    a3[1] = 2;
    a3[2] = 3;

    printf("in main %s:%d\n","a1",(int) sizeof(a1));
    printf("in main %s:%d\n","a2",(int) sizeof(a2));
    printf("in main %s:%d\n","a3",(int) sizeof(a3));
    printf("in main %s:%d\n","a4",(int) sizeof(a4));

    druckeSizeOfArray(a1,"a1");
    druckeSizeOfArray(a2,"a2");
    druckeSizeOfArray(a3,"a3");
    druckeSizeOfArray(a4,"a4");

    druckeSizeOfArrayPtr(a1,"a1");
    druckeSizeOfArrayPtr(a2,"a2");
    druckeSizeOfArrayPtr(a3,"a3");
    druckeSizeOfArrayPtr(a4,"a4");

    return OK;
}
