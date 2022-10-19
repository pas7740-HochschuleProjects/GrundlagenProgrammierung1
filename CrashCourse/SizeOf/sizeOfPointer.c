/* Prints size of pointers to the console  */
/* Note: results depend on machine model AND compiler */

#include <stdio.h>
#define OK 0

struct pos {
    int row;
    int col;
};

int main() {
    printf("         char*:\t%02d Bits\n",sizeof(char*)*8); 
    printf("          int*:\t%02d Bits\n",sizeof(int*)*8); 
    printf("         void*:\t%02d Bits\n",sizeof(void*)*8); 
    printf("   struct pos*:\t%02d Bits\n",sizeof(struct pos*)*8); 

    return OK;
}
