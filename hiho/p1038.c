#include <stdio.h>
#include <stdlib.h>

#define SIZE (100000+10)

int w[500], v[500];
int f[SIZE];

int main(int argc, char *argv[]) {
    int N, M;
    scanf("%d%d", &N, &M);
    int i, j;
    for (i=0; i<N; i++) {
        scanf("%d%d", &w[i], &v[i]);
    }
    memset(f, 0, SIZE*sizeof(int));

    for (i=0; i<N; i++) {
        for (j=M; j>=w[i]; j--) {
            if (f[j] < f[j-w[i]]+v[i]) {
                f[j] = f[j-w[i]] + v[i];
            }
        }
    }

    printf("%d\n", f[M]);
    return 0;
}
