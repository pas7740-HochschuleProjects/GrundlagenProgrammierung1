#include <stdio.h>

int main() {
  int fahrenheitWert;
  fahrenheitWert = 0;

  printf("Grad Fahrenheit\tGrad Celsius\n");
  while (fahrenheitWert <= 300) {
    int celsiusWert;
    celsiusWert = 5/9.0 * (fahrenheitWert - 32);

    printf("%10d\t%7d\n", fahrenheitWert,celsiusWert);
    fahrenheitWert = fahrenheitWert + 20;
  }
  return 0;
}
