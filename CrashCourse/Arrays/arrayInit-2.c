/* 
 * Array initialization
 * Initializeing local arrays.
 * 
 * From standard C89 on:
 * 
 * Local variables are not automatically initialized to 0.
 * This is only true for arrays defined globally.
 *
 * However, by using the explicit initializer = {0}
 * one can set all elements to 0!
 *
 * Beware of semantics of = {4,5}
 * ==> a[0] = 4
 *     a[1] = 5
 *     a[n] = 0 for n >= 2 upto to SIZE-1 
 *
 *
 * Hint:
 * use the shell command
 *   gdb -q bin/arrayInit-2 -ex "disassemble /m main" -ex quit
 *
 * and inspect the resulting assembler code.
 * Observe the changes resulting from variations of
 * CPP constant SIZE.
 */

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int main(void){
  int i;

  /* int la[SIZE]={0}; */
  int la[SIZE]={4,5}; 

  printf("Initial values of array:\n");
  for(i=0; i< SIZE; i++){
    printf("la[%d]=%d\n", i, la[i]);
  }

  return EXIT_SUCCESS;
}

