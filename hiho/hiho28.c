#include <stdio.h>
#include <stdlib.h>

int heap[100100];
int length;

void swap(int x, int y) {
    int t;
    t = heap[x]; heap[x] = heap[y]; heap[y] = t;
}

void insert(int e) {
    heap[length] = e;
    int k = length;
    length++;
    while (k>0 && heap[k]>heap[k/2]) {
        swap(k, k/2);
        k /= 2;
    }
}

int pop() {
    int res = heap[0];
    heap[0] = heap[length-1];
    length--;
    int k = 0;
    while (2*k < length) {
        int t = 2*k;
        if (2*k+1 < length && heap[2*k] < heap[2*k+1]) {
            t = 2*k+1;
        }
        if (heap[t] > heap[k]) {
            swap(t, k);
            k = t;
        } else {
            break;
        }
    }
    return res;
}

int main() {
    int N; 
    scanf("%d", &N);
    
    int length = 0;

    int i, w, maxi;
    char mode;
    for (i=0; i<N; i++) {
        scanf("\n%c", &mode);
        if (mode == 'A') {
            scanf("%d", &w);
            insert(w);
        } else {
            maxi = pop();
            printf("%d\n", maxi);
        }
    }
    return 0;
}
