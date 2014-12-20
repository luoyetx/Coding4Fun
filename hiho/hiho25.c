#include <stdio.h>
#include <stdlib.h>

#define BOOL int
#define TRUE 1
#define FALSE 0
#define MAX 1000000000

typedef struct Node {
    int val;
    int weight;
    struct Node* next;
} Node;

int main(int argc, char* argv[]) {
    int N, M, s, t;
    scanf("%d%d%d%d", &N, &M, &s, &t);
    ++N;
    // link table
    Node** links = (Node**)malloc(sizeof(Node*)*N);
    int i;
    for (i=1; i<N; i++) {
        links[i] = (Node*)malloc(sizeof(Node));
        links[i]->val = i;
        links[i]->weight = 0;
        links[i]->next = NULL;
    }
    // get path in G
    int x, y, w;
    for (i=0; i<M; i++) {
        scanf("%d%d%d", &x, &y, &w);
        Node* no = (Node*)malloc(sizeof(Node));
        no->val = y;
        no->weight = w;
        no->next = links[x]->next;
        links[x]->next = no;
        no = (Node*)malloc(sizeof(Node));
        no->val = x;
        no->weight = w;
        no->next = links[y]->next;
        links[y]->next = no;
    }
    // init distance
    int* dd = (int*)malloc(sizeof(int)*N);
    for (i=1; i<N; i++) {
        dd[i] = MAX;
    }
    dd[s] = 0;
    // SPFA
    BOOL* in_queue = (BOOL*)malloc(sizeof(BOOL)*N);
    for (i=0; i<N; i++) {
        in_queue[i] = FALSE;
    }
    int* queue = (int*)malloc(sizeof(int)*N);
    int l, r;
    l = 0; r = 1;
    queue[l] = s;
    in_queue[s] = TRUE;

    while (l != r) {
        int k = queue[l];
        Node* p = links[k]->next;
        while (p != NULL) {
            if (dd[k] + p->weight < dd[p->val]) { // expandable
                dd[p->val] = dd[k] + p->weight;
                if (!in_queue[p->val]) { // not in queue
                    queue[r] = p->val;
                    in_queue[p->val] = TRUE;
                    r = (r+1)%N;
                }
            }
            p = p->next;
        }
        l = (l+1)%N;
        in_queue[k] = FALSE;
    }
    // result
    printf("%d\n", dd[t]);

    // free all
    free(in_queue);
    free(queue);
    free(dd);
    for (i=0; i<N; i++) {
        Node* p= links[i];
        while (p != NULL) {
            links[i] = p->next;
            free(p);
            p = links[i];
        }
    }
    free(links);
    return 0;
}
