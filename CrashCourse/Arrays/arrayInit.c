// Array initialization
// What is possible?
// What is impossible?
// 
// Baseline: C11

#include<stdio.h>
#include<stdlib.h>

// Global arrays

int x = 3;

int ga1[3] = {1,2,3};
int ga2[3] = {1,1+1,3};
int ga3[3] = {1,23%3,3};

// Note: complex expressions in the initializer list of global arrays
//       are not allowed. Expressions need to be evaluated at compile time!

// int ga4[3] = {1,x,3};   // error: initializer element is not constant

int main(void){
  int y = 3;

  // Note: complex expressions in the initializer list of local arrays
  // are (almost) no problem. The expressions are evaluated at runtime.

  int la1[3] = {1,2,3};
  int la2[3] = {1,1+1,3};
  int la3[3] = {1,23%3,3};
  int la4[3] = {1,x,3};
  int la5[3] = {1,y,3};
  
  //int la6[3+x+y] = {1,y,3}; // error: variable-sized object may not be initialized

  int la7[3+x+y];       // Variable-sized arrays are allowed since C99;
                        // The array is allocated in the stack; fragile!!
                        // However, they cannot be initialized.

  // The rest:
  // Just to avoid warnings about unused variables
  la7[0] = 21;

  printf("%d\n", y);
  printf("%d\n", la1[0]);
  printf("%d\n", la2[0]);
  printf("%d\n", la3[0]);
  printf("%d\n", la4[0]);
  printf("%d\n", la5[0]);
  printf("%d\n", la7[0]);

  return EXIT_SUCCESS;
}
