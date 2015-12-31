#include <stdio.h>
#include <stdlib.h>

#undef ACCUM_WITHOUT_ARITHM_DEBUG

int accumulatorWithoutAirthmaticOperator(int m, int n)
{
    if(n == 0)
        return m;
    
    int carry = (m & n) << 1;
    int sum = m ^ n;
#ifdef ACCUM_WITHOUT_ARITHM_DEBUG    
    printf("m & n = %d, carry (m & n << 1) = %d  sum(m^n) = %d\n", (m & n), ((m & n) << 1), (m^n));
#endif
    return accumulatorWithoutAirthmaticOperator(sum, carry);
}

#ifdef ACCUM_WITHOUT_ARITHM_DEBUG
int main(int argc, char* argv[])
{
    int m = 41;
    int n = 41;

    printf(" %d + %d = %d\n", m, n, accumulatorWithoutAirthmaticOperator(m, n));;
 return 0;
}
#endif