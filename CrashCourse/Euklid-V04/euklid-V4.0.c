#include <stdio.h>
#define OK 0
#define ERROR 1

int main (void) {
  int i1;
  int i2;

  /* Lies zwei ganze Zahlen in i1 und i2 ein */
  printf("i1 = ");
  fflush(stdout);

  if(scanf("%d", &i1) != 1) {
    printf("Fehler bei der Eingabe der Zahl i1\n");
    return ERROR;
  }
  while(getchar() != '\n');

  printf("i2 = ");
  fflush(stdout);
  if(scanf("%d", &i2) != 1) {
    printf("Fehler bei der Eingabe der Zahl i2\n");
    return ERROR;
  }
  while(getchar() != '\n');

  // Eingegebene Werte i1, i2 in a, b umspeichern: Wieso?
  int a = i1;
  int b = i2;
  while (a != b) {
    if (a < b) {
      b = b - a;
    } else {
      a = a - b;
    }
  }
  printf ("Der groesste gemeinsame Teiler von %d und %d ist: %d\n",
      i1, i2, a);
  return OK;
}
