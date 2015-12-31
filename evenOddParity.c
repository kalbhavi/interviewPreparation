#include <stdio.h>
#include <stdlib.h>

#undef EVEN_ODD_PARITY_DEBUG

#define TRUE 1
#define FALSE 0
typedef unsigned char bool;

bool isOddParity(long num)
{
    int bitCountToggle = 1;
    while (num != 0){
        bitCountToggle ^= 1;
        num = num & (num - 1); 
    }
    return (bitCountToggle == 0) ? TRUE : FALSE;
}

#ifdef EVEN_ODD_PARITY_DEBUG 
int main(int argc, char* argv[])
{
    for(int i = 0; i < 10; ++i){
        if(isOddParity(i) == TRUE)
            printf(" %d has odd parity\n", i);
        else
            printf(" %d has even parity\n", i);
    }
    return 0;
}
#endif