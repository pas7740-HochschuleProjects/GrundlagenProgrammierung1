// Verbesserung der Version euklid-V4.2
// readInteger: Einlesen einer Integer-Zahl

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

int readInteger(int* addr_n){
  int retcode;
  if(scanf("%d", addr_n) != 1) {
    retcode = ERROR;
  } else {
    retcode = OK;
  }
  while(getchar() != '\n'){/* NOP */}
  return retcode;
}

int main (void) {
  int i1;
  int i2;

  /* Lies zwei ganze Zahlen in i1 und i2 ein */
  printf("i1 = ");
  fflush(stdout);
  if(readInteger(&i1) != OK ) {
    printf("Fehler bei der Eingabe der Zahl i1\n");
    return ERROR;
  }

  printf("i2 = ");
  fflush(stdout);
  if(readInteger(&i2) != OK ) {
    printf("Fehler bei der Eingabe der Zahl i1\n");
    return ERROR;
  }

  printf ("Der groesste gemeinsame Teiler von %d und %d ist: %d\n",
      i1, i2, ggT(i1,i2));
  return OK;
}
