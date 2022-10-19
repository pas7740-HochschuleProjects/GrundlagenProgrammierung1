#include <stdio.h>

int main() {
    char meldung[] = "Hello";
    int i;

    i=0;
    while(meldung[i] != '\0') {
        printf("%c - %3d\n", meldung[i], meldung[i]);
        i++;
    }
    printf("\n");

    return 0;
}

