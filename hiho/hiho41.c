#include <stdio.h>

int bit[100];
long long matrix[2][2] = {{1, 1}, {1, 0}};
long long base[2][2] = {{1, 1}, {1, 0}};

void matrix_mul(long long x[2][2], long long y[2][2]) {
    // x: 2x2, y: 2x2
    // result is stored in x
    int i, j, k;
    long long z[2][2];
    for (i=0; i<2; i++) {
        for (j=0; j<2; j++) {
            z[i][j] = 0;
            for (k=0; k<2; k++) {
                z[i][j] += x[i][k] * y[k][j];
#define DEF 19999997
                    z[i][j] %= DEF;
#undef DEF
            }
        }
    }
    for (i=0; i<2; i++) {
        for (j=0; j<2; j++) {
            x[i][j] = z[i][j];
        }
    }
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int len = 0;
    while (n > 0) {
        bit[len] = n % 2;
        n /= 2;
        len++;
    }
    int i, j, k;
    for (k=len-2; k>=0; k--) {
        // matrix * matrix
        matrix_mul(matrix, matrix);
        if (bit[k] == 1) {
            matrix_mul(matrix, base);
        }
    }
    long long res = matrix[0][0];
    printf("%ld", res);
    return 0;
}
