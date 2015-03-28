#include <stdio.h>

int a[100010];
int b[100010];

int sort(int l, int r) {
    if (l >= r) {
        return 0;
    }
    int mid = (l+r)/2;
    int res1 = sort(l, mid);
    int res2 = sort(mid+1, r);
    int res = res1 + res2;
    int i = l;
    int j = mid+1;
    int k;
    for (k=l; k<=r; k++) {
        if (j > r) { 
            b[k] = a[i];
            i++;
        }
        else if (i > mid) {
            b[k] = a[j];
            j++;
        }
        else if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        }
        else {
            b[k] = a[j];
            j++;
            res += mid - i + 1;
        }
    }
    for (k=l; k<=r; k++) {
        a[k] = b[k];
    }
    return res;
}

int main(int argc, char* argv[]) {
    int N;
    scanf("%d", &N);
    int i;
    for (i=0; i<N; i++) {
        scanf("%d", &a[i]);
    }
    int res = sort(0, N-1);
    printf("%d\n", res);
    return 0;
}
