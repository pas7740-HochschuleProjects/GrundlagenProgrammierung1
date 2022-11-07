#include <stdio.h>

void weristkacke(int z) {
  if (z == 0){
    printf("miggi ist kacke\n");
  }
  else if (z == 1){
    printf("pastell ist kacke\n");
  }
  else {printf("du bist kacke\n");
  }
}

int main(){
  int zahl = 0;
  weristkacke(zahl);
  return 0;
}
