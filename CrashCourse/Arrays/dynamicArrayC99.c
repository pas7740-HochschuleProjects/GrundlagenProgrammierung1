// This example demonstrates
//   - initialization by result of a function: int x = max(2,3)
//   - C99 declaration of a local array with dynamic size: int a[x]
//   - C99 definition of the variable controlling a loop: for (int i =0; ...)

#include <stdio.h>

int max(int a, int b){
  int max;
  if (a >= b) {
    max = a;
  } else {
    max = b;
  }
  return max;
}

int main(void){
  int x = max(2,3);
  printf("The max is %d\n", x);

  int a[x];
  for(int i=0; i< x; i++){
    a[i] = i;
  }

  for(int i=0; i< x; i++){
    printf("a[%d] = %d\n", i, a[i]);
  }
  return 0;
}
