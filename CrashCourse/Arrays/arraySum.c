#include <stdio.h>

int main() {
    int values[10]= {1,2,3,4,5,6,7,8,9,10};
    int sum;
    int i;

    sum=0;
    for (i = 0; i< 10; i++) {
        sum += values[i];
    }
    printf("Die Summe ist: %d\n",sum);
    return 0;
}

