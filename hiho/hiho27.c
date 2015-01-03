#include <stdio.h>

int x[1000100];
int y[1000100];
int w[1000100];
int fa[1000100];

inline void swap(int* a, int i, int j) {
    int tmp;
    tmp = a[i]; a[i] = a[j]; a[j] = tmp;
}

void qsort(int l, int r) {
    int i, j, t;
    i = l; j = r;
    t = w[(i+j) >> 1];
    do {
        while (w[i] < t) i++;
        while (w[j] > t) j--;
        if (i <= j) {
            swap(x, i, j);
            swap(y, i, j);
            swap(w, i, j);
            i++; j--;
        }
    } while (i <= j);
    if (l < j) qsort(l, j);
    if (i < r) qsort(i, r);
}

int getFather(int k) {
    if (fa[k] == k) {
        return k;
    } else {
        int _fa = getFather(fa[k]);
        fa[k] = _fa;
        return _fa;
    }
}

int main(int argc, char* argv[]) {
    int N, M;
    scanf("%d%d", &N, &M);
    
    int i, j, k;
    int _x, _y, _w;
    for (i=0; i<M; i++) {
        scanf("%d%d%d", &_x, &_y, &_w);
        x[i] = _x; y[i] = _y; w[i] = _w;
    }

    qsort(0, M-1);

    for (i=0; i<N; i++) {
        fa[i] = i;
    }
    
    int p = 0;
    int result = 0;
    for (k=1; k<N; k++) {
        while (p < M && getFather(x[p]) == getFather(y[p])) p++;
        result += w[p];
        fa[getFather(x[p])] = getFather(y[p]);
    }

    printf("%d\n", result);
    return 0;
}
