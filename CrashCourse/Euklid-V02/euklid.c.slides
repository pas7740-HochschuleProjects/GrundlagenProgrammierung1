#include <stdio.h>
#define OK 0
#define ERROR 1

int main (void) {
    int x;
    int y;

    printf("x= ");
    scanf("%d", &x);

    printf("y= ");
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
