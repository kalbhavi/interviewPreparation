#include <stdio.h>
#include <stdlib.h>

#define ENDIANESS_DEBUG 1

#define TRUE    1
#define FALSE   0


unsigned char isLittleEndian()
{
    int num = 0x1;
    char *p = (char *)&num;
    return (*p) ? 1 : 0;
}

unsigned char isLittleEndian2()
{
    union {
        int a;
        char b;
    }endianess;
    endianess.a = 1;
    return (endianess.b == 1)? TRUE : FALSE;
}


#ifdef ENDIANESS_DEBUG
int main(int argc, char* argv[])
{
    if(isLittleEndian()){
        printf("The given machine is little endian\n");
    }
    else{
        printf("The given machine is big endian\n");
    }

    if(isLittleEndian2()){
        printf("The given machine is little endian\n");
    }
    else{
        printf("The given machine is big endian\n");
    }
    return 0;
}
#endif