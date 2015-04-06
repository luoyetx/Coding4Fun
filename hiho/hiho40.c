#include <stdio.h>
#include <math.h>

int a, b, c, x, y;

float f(float xs) {
    return a*xs*xs+b*xs+c;
}

float dd(float xs) {
    float ys = f(xs);
    return sqrt((xs-x)*(xs-x)+(ys-y)*(ys-y));
}

int main(int argc, char *argv[]) {
    scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
    float xl, xlm, xrm, xr;
    if (a != 0) {
        float mid;
        mid = -1.0 * b / (2*a);
        xl = (mid < x ? mid : -1000);
        xr = (mid > x ? mid : 1000);
    }
    else {
        xl = -1000; xr = 1000;
    }
    int iter = 0;
    while (1) {
        xlm = xl + (xr-xl)/3;
        xrm = xl + (xr-xl)*2/3;
        float d1 = dd(xlm);
        float d2 = dd(xrm);
        if (d1 < d2) {
            xr = xrm;
        }
        else {
            xl = xlm;
        }
        if (iter == 2000) {
            break;
        }
        else {
            iter++;
        }
    }
    printf("%.3f\n", dd(xlm));
    return 0;
}
