
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define INT_MIN     (-2147483647 - 1)
#define INT_MAX      2147483647

#define TRUE	1
#define FALSE	0
#define BOOL	unsigned char

int atoi(const char *str) {
    int ret=0;
    BOOL negativeSign = FALSE;
    
    if (str==NULL || *str=='\0'){
        return 0;
    }
    
    /* Remove the leading spaces */
    for(;isspace(*str); str++);
    
    /* Check for negative or positive sign at the begining */
    if (*str=='-' || *str=='+') {
        negativeSign = (*str=='-') ;
        str++;
    }
    
    for(; *str != '\0' && isdigit(*str); str++) {
        int digit = (*str-'0');
        
        if(negativeSign){
            if( -ret < (INT_MIN + digit)/10 ) {
                return INT_MIN;
            }
        }else{
            if( ret > (INT_MAX - digit) /10 ) {
                return INT_MAX;
            }
        }

        ret = (10 * ret) + digit ;
    }
    
    return negativeSign ? -ret : ret;
}


int main()
{
    printf("\"%s\" = %d\n", "123", atoi("123"));
    printf("\"%s\" = %d\n", "   123", atoi("    123"));
    printf("\"%s\" = %d\n", "+123", atoi("+123"));
    printf("\"%s\" = %d\n", " -123", atoi(" -123"));
    printf("\"%s\" = %d\n", "123ABC", atoi("123ABC"));
    printf("\"%s\" = %d\n", " abc123ABC", atoi(" abc123ABC"));
    printf("\"%s\" = %d\n", "2147483647", atoi("2147483647"));
    printf("\"%s\" = %d\n", "-2147483648", atoi("-2147483648"));
    printf("\"%s\" = %d\n", "2147483648", atoi("2147483648"));
    printf("\"%s\" = %d\n", "-2147483649", atoi("-2147483649"));
    return 0;
}
