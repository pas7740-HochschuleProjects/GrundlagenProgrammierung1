#include<stdio.h>

int main(void){
    int num, intWert;
    float floatWert;

    num = scanf("%d,%f", &intWert, &floatWert);

    if(num!=2) {
        printf("Fehler bei der Eingabe\n");
    } else {
        printf("EIngabe: intWert= %d, floratWert= %f\n", intWert, floatWert);
    }

    return 0;
}
