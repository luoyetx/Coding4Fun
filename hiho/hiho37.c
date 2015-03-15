#include <stdio.h>

int a[1000100];

int qsort(int l, int r, int k) {
    int first, last, key;
    first = l; last = r;
    key = a[last];
    while (first < last) {
        while (first<last && a[first]<=key) first++;
        a[last] = a[first];
        while (first<last && a[last]>=key) last--;
        a[first] = a[last];
    }
    a[first] = key;
    if (first == k) return a[first];
    if (l <= first-1 && first > k) return qsort(l, first-1, k);
    if (r >= first+1 && first < k) return qsort(first+1, r, k);
    return -1;
}

int main(int argc, char* argv[]) {
    int N, k;
    scanf("%d%d", &N, &k);
    int i;
    for (i=0; i<N; i++) scanf("%d", a+i);
    k--;
    if (k<0 || k>=N) {
        printf("-1\n");
        return 0;
    }
    int result = qsort(0, N-1, k);
    printf("%d\n", result);
    return 0;
}