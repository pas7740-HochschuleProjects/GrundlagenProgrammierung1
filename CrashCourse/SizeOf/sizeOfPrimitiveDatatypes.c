/* Prints size of primitive datatypes tp the console  */
/* Note: results depend on machine model AND compiler */

#include <stdio.h>
#define OK 0

int main() {
    printf("         char:\t%02d Bits\n",sizeof(char)*8); 
    printf("        short:\t%02d Bits\n",sizeof(short int)*8); 
    printf("          int:\t%02d Bits\n",sizeof(int)*8); 
    printf("     long int:\t%02d Bits\n",sizeof(long int)*8); 
    printf("long long int:\t%02d Bits\n",sizeof(long long int)*8); 
    printf("        float:\t%02d Bits\n",sizeof(float)*8); 
    printf("       double:\t%02d Bits\n",sizeof(double)*8); 
    printf("  long double:\t%02d Bits\n",sizeof(long double)*8); 

    return OK;
}
