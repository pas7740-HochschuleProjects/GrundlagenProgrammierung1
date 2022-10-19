#include <stdio.h>

#define OK 0
#define ERROR 1

#define STARTWERT 0
#define ENDWERT   300
#define SCHRITTWEITE 20

int main() {
    int fhwert;

    printf("Startwert=%d, Endwert=%d, Schrittweite=%d\n",STARTWERT,ENDWERT,SCHRITTWEITE);
    printf("Grad Fahrenheit\tGrad Celsius\n");
    for (fhwert = STARTWERT; fhwert <= ENDWERT;  
            fhwert = fhwert + SCHRITTWEITE) {
        printf("%10d\t%7.1f\n", fhwert, (5.0/9.0)*(fhwert-32));
    }
    return OK;
}
