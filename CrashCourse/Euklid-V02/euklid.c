#include <stdio.h>
#define OK 0
#define ERROR 1

int main (void) {
    int x, y, z;

    getchar(); // Stop für Einstieg des gdb in zweitem Fenster
    printf("Bitte x eingeben: ");

    z=4711; // dummy
    scanf("%d", &x);

    printf("Bitte y eingeben: ");

    z=2*z; // dummy
    scanf("%d", &y);

    while (x != y) {
        if (x < y)
            y = y - x;
        else
            x = x - y;
    }
    printf ("Der groesste gemeinsame Teiler ist: %d\n", x);
    return OK;
}
