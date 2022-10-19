#include <stdio.h>
#define OK 0
#define ERROR 1

int main (void) {
    /* Lies zwei Ganzahlen >= 0 ein und weise sie x und y zu ;
     * Das koennen wir noch nicht.
     * Daher werden x und y im Code mit Zahlen belegt.
     */
    int x = 24;
    int y = 9;

    while (x > 0) {
        if (x < y) {
            /* Vertausche x und y; */
            int tmp;
            tmp = x;
            x = y;
            y = tmp;
        }
        x = x - y;
    }

    /* Ausgabe von y; */
    printf ("Der groesste gemeinsame Teiler ist: %d\n", y);
    return OK;
}
