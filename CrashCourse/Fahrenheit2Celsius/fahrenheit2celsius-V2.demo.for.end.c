#include <stdio.h>

int main() {
  printf("Grad Fahrenheit\tGrad Celsius\n");
  for ( int fahrenheitWert = 0;
      fahrenheitWert <= 300;
      fahrenheitWert += 20){

    int celsiusWert;
    celsiusWert = 5/9.0 * (fahrenheitWert - 32);

    printf("%10d\t%7d\n", fahrenheitWert,celsiusWert);
  }
  return 0;
}
