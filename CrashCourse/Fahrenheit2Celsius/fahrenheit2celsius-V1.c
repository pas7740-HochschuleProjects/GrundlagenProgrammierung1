#include <stdio.h>
#define OK 0

int main() {
  int fahrenheitWert;
  fahrenheitWert = 0;

  printf("Grad Fahrenheit\tGrad Celsius\n");
  while (fahrenheitWert <= 300) {
    int celsiusWert;
    celsiusWert = 5/9 * (fahrenheitWert - 32);

    printf("%d\t%d\n", fahrenheitWert,celsiusWert);
    fahrenheitWert = fahrenheitWert + 20;
  }
  return OK;
}
