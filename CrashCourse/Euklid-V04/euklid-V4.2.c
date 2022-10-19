// Verbesserung der Version euklid-V4.1
// ggT erlaubt nun auch negative Zahlen als Argumente

#include <stdio.h>
#define OK 0
#define ERROR 1

int ggT(int a, int b) {
  // Fix fuer negative Zahlen
  if (a < 0) {
    a = -a;
  }
  if (b < 0) {
    b = -b;
  }

  while (a != b) {
    if (a < b) {
      b = b - a;
    } else {
      a = a - b;
    }
  }
  return a;
}

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

  printf ("Der groesste gemeinsame Teiler von %d und %d ist: %d\n",
      i1, i2, ggT(i1,i2));
  return OK;
}
