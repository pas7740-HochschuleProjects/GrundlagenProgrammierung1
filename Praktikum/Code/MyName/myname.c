#include<stdio.h>

int main(){
  char* name = "Pascal Schwab";
  int day = 4, month = 6, year = 2003;
  printf("Mein Name ist %s\n", name);
  printf("Mein Geburtsdatum ist der %02d.%02d.%04d\n", day, month, year);
  return 0;
}
