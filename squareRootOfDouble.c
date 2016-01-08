#include <stdio.h>

#define SQRT_DOUBLE_DEBUG 1

double absoluteValue (double x) {
    if ( x < 0 )
        x = -x;
    return (x);
}

/* This function calculates the square root of given double/double by using newton rapson method */
double squareRootDouble (double x) {
    const double epsilon = .00001;
    double guess = 1.0;
    while ( absoluteValue (guess * guess - x) >= epsilon ) {
        guess = ( x / guess + guess ) / 2.0;
        printf("Guess = %f \n", guess);
    }
    return guess;
}

#ifdef SQRT_DOUBLE_DEBUG
int main (void) {
    printf ("squareRoot (2.0) = %f \n \n ", squareRootDouble (2.0));
    printf ("squareRoot (144.0) = %f \n \n", squareRootDouble (144.0));
    printf ("squareRoot (17.5) = %f \n \n", squareRootDouble (17.5));
return 0;
}
#endif