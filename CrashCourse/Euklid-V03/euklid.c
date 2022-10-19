#include <stdio.h>
#define OK 0
#define ERROR 1

int main (void) {
    int x;
    int y;
    /* Lies zwei ganze Zahlen in x und y ein */
    //setvbuf(stdout, NULL, _IONBF, 0);
    printf("x = ");
    /* Achtung: es ist nicht garantiert, dass die Ausgabe hier wirklich sofort am Bildschirm
     * erscheint. Dies ist nur dann der Fall, wenn stdout nicht gepuffert wird.
     * Will man sicher gehen, dass die Ausgabe rechtzeitig erfolgt, muss man entweder
     * a) ein fflush(stdout) machen oder alternativ
     * b) den Ausgabe-Kanal explizit auf ungepuffert setzen, vor der ersten Ausgabe!.
     *    setvbuf(stdout, NULL, _IONBF, 0)
     * Der C-Standard garantiert die Ausgabe nicht, auch nicht, wenn '\n' am Ende steht.
     */
    fflush(stdout);
    if(scanf("%d", &x) != 1) {
        printf("Fehler bei der Eingabe\n");
        return ERROR;
    }

    printf("y = ");
    fflush(stdout);
    if(scanf("%d", &y) != 1) {
        printf("Fehler bei der Eingabe\n");
        return ERROR;
    }

    while (x != y) {
        if (x < y)
            y = y - x;
        else
            x = x - y;
    }
    printf ("Der groesste gemeinsame Teiler ist: %d\n", x);
    return OK;
}
