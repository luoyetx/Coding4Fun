#include <iostream>

using namespace std;

int w[1100][1100];
int d[1100];
bool vis[1100];

int main(int argc, char* argv[]) {

    const int MAX = 1000000000;
    int N, M, S, T;

    while (cin >> N) { // wrapper begin.
    cin >> M >> S >> T;

    // init w
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            w[i][j] = MAX;
        }
    }
    // get w
    for (int i=0; i<M; i++) {
        int x, y, wei;
        cin >> x >> y;
        cin >> wei;
        if (wei < w[x][y]) {
            w[x][y] = w[y][x] = wei;
        }
    }
    // init distance && visited
    for (int i=1; i<=N; i++) {
        d[i] = MAX;
        vis[i] = false;
    }
    // for S
    d[S] = 0;
    // Dijkstra algorithm
    int last_one = S;
    while (last_one != T) {
        int min = MAX;
        // find min
        for (int i=1; i<=N; i++) {
            if (!vis[i] && d[i] < min) {
                last_one = i;
                min = d[i];
            }
        }
        vis[last_one] = true;
        // update
        for (int i=1; i<=N; i++) {
            if (!vis[i] && (min+w[last_one][i]<d[i])) {
                d[i] = min + w[last_one][i];
            }
        }
    }
    // result
    cout << d[T] << endl;


    } // wrapper end.
    return 0;
}
