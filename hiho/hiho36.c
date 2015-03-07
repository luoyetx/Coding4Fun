#include <stdio.h>

int a[1000000];

int qsort(int l, int r) {
    int i, j, t;
    i = l; j = r;
    t = a[(l+r)/2];
    do {
        while (a[i] < t) i++;
        while (a[j] > t) j--;
        if (i <= j) {
            int tmp;
            tmp = a[i]; a[i] = a[j]; a[j] = tmp;
            i++; j--;
        }
    } while (i<=j);
    if (l < j) qsort(l, j);
    if (i < r) qsort(i, r);
}

int main(int argc, char* argv[]) {
    int n, i, k;
    scanf("%d%d", &n, &k);
    for (i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(0, n-1);
    int result = -1;

    for (i=0; i<n; i++) {
        if (a[i] == k) result = i+1;
    }

    printf("%d\n", result);
    return 0;
}
