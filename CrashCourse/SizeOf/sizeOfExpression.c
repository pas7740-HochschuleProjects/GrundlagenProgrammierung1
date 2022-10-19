/* Prints size of primitive datatypes tp the console  */
/* Note: results depend on machine model AND compiler */

#include <stdio.h>
#define OK 0

int main() {
    printf(" 2    :\t%02d Bits\n",sizeof(2)*8); 
    printf(" 2l   :\t%02d Bits\n",sizeof(2l)*8); 
    printf(" 2ll  :\t%02d Bits\n",sizeof(2ll)*8); 
    printf(" 2.0  :\t%02d Bits\n",sizeof(2.0)*8); 
    printf(" 2.0f :\t%02d Bits\n",sizeof(2.0f)*8); 
    printf(" 2.0l :\t%02d Bits\n",sizeof(2.0l)*8); 

    return OK;
}
