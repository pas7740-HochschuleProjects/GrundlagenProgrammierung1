// Verbesserung der Version euklid-V4.3
//
// - Einlesen einer Integerzahl mit Prompt durch Funktion readInteger.
//   Mehrere Fehlversuche sind erlaubt.
// - Verwendung des Datentyps bool

#include <stdio.h>
#include <stdbool.h>    // Neuer Datentyp bool
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

int readInteger(char* prompt, int* addr_n) {
  bool erfolg = false; // Neuer Typ bool:
  // Konstanten true, false
  int zaehler = 2;     // Anzahl der Versuche

  while (!erfolg && zaehler > 0) {
    printf("%s",prompt);
    fflush(stdout);

    if(scanf("%d", addr_n) != 1) {
      zaehler--;
      printf("Sie muessen hier eine Zahl eingeben!!!\n");
    } else {
      erfolg = true;
    }
    while(getchar() != '\n'){/* NOP */}
  }

  // Stelle fest, wieso wir Schleife verlassen haben
  int rescode;
  if (!erfolg) {
    rescode=ERROR;
  } else {
    rescode=OK;
  }
  return rescode;
}

int main (void) {
  int i1, i2;
  /* Lies zwei ganze Zahlen in i1 und i2 ein */

  if(readInteger("i1= ", &i1) != OK ) {
    printf("Fehler bei der Eingabe der Zahl i1\n");
    return ERROR;
  }

  if(readInteger("i2= ", &i2) != OK ) {
    printf("Fehler bei der Eingabe der Zahl i2\n");
    return ERROR;
  }

  printf ("Der groesste gemeinsame Teiler von %d und %d ist: %d\n",
      i1, i2, ggT(i1,i2));
  return OK;
}
