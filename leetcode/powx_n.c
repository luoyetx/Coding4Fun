#include <stdio.h>
#include <math.h>

double myPow(double x, int n) {
    return pow(x, n);
}


int main(void) {
    printf("%lf\n", myPow(8.88023, 3));
    return 0;
}