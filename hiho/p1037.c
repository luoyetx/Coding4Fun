#include <stdio.h>

int a[200][200];
int f[200][200];

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    int i, j;
    for (i=0; i<n; i++) {
        for (j=0; j<=i; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    f[0][0] = a[0][0];
    for (i=1; i<n; i++) {
        f[i][0] = a[i][0] + f[i-1][0];
        f[i][i] = a[i][i] + f[i-1][i-1];
        for (j=1; j<i; j++) {
            if (f[i-1][j-1] > f[i-1][j]) {
                f[i][j] = a[i][j] + f[i-1][j-1];
            }
            else {
                f[i][j] = a[i][j] + f[i-1][j];
            }
        }
    }
    int result = -1;
    i = n-1;
    for (j=0; j<n; j++) {
        if (f[i][j] > result) {
            result = f[i][j];
        }
    }
    printf("%d\n", result);
    return 0;
}
