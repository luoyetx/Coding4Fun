#include <stdio.h>

const int MAX = 100000000;
int map[1100][1100];
int distance[1100];
int vis[1100];

int main(int argc, char* argv[]) {
    int N;
    scanf("%d", &N);
    
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            scanf("%d",&map[i][j]);
        }
    }

    for (i=0; i<N; i++) {
        distance[i] = MAX;
        vis[i] = 0;
    }

    int source = 0;
    distance[source] = 0;
    
    int result = 0;
    while (1) {
        int k = -1;
        int min = MAX;
        for (i=0; i<N; i++) {
            if (!vis[i] && distance[i] < min) {
                min = distance[i];
                k = i;
            }
        }
        if (k == -1) {
            break;
        }
        vis[k] = 1;
        result += min;
        for (i=0; i<N; i++) {
            if (map[k][i] < distance[i]) {
                distance[i] = map[k][i];
            }
        }
    }

    printf("%d\n", result);
    return 0;
}
