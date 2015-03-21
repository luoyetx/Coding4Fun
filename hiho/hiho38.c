#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_SIZE 10010
#define MAX_K 1000001

struct link {
    int node;
    int weight;
    struct link *next;
};

struct link **map;
int q[MAX_SIZE], v[MAX_SIZE], len[MAX_SIZE];

int attack(int source, int target, int max_weight, int max_len) {
    int i, j;
    q[0] = source;
    memset(v, 0, MAX_SIZE*sizeof(int));
    memset(len, 0, MAX_SIZE*sizeof(int));
    v[source] = 1;
    len[source] = 0;
    int head, tail;
    head = 0; tail = head + 1;
    while (head != tail) {
        int s = q[head];
        if (s == target) {
            return 1;
        }
        if (len[s] == max_len) {
            head++;
            continue;
        }
        struct link *p = map[s];
        while (p) {
            if (p->weight <= max_weight && !v[p->node]) {
                v[p->node] = 1;
                len[p->node] = len[s] + 1;
                q[tail] = p->node;
                tail++;
            }
            p = p->next;
        }
        head++;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int N, M, K, T;
    scanf("%d%d%d%d", &N, &M, &K, &T);
    int i, j;
    map = (struct link**)malloc(sizeof(struct link*) * (N+1));
    for (i=0; i<N; i++) {
        map[i] = NULL;
    }
    for (i=0; i<M; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        struct link *p = (struct link*)malloc(sizeof(struct link));
        p->node = v;
        p->weight = w;
        p->next = map[u];
        map[u] = p;
        p = (struct link*)malloc(sizeof(struct link));
        p->node = u;
        p->weight = w;
        p->next = map[v];
        map[v] = p;
    }

    int left, right, mid;
    left = 0;
    right = MAX_K;
    while (left < right-1) {
        mid = (left + right) / 2;
        if (attack(1, T, mid, K)) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    printf("%d\n", right);
    for (i=0; i<N; i++) {
        struct link *p = map[i];
        while (p) {
            struct link *q = p->next;
            free(p);
            p = q;
        }
    }
    free(map);
    return 0;
}
