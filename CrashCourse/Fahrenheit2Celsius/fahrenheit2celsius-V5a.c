#include <stdio.h>

#define OK 0
#define ERROR 1

int main() {
    int fhwert;

    printf("Startwert=%d, Endwert=%d, Schrittweite=%d\n",0,300,20);
    printf("Grad Fahrenheit\tGrad Celsius\n");
    for (fhwert = 0; fhwert <= 300;  
            fhwert = fhwert + 20) {
        printf("%10d\t%7.1f\n", fhwert, (5.0/9.0)*(fhwert-32));
    }
    return OK;
}
