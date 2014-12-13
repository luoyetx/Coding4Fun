#include <iostream>

using namespace std;

int d[200][200];

int main(int argc, char* argv[]) {
    
    const int MAX = 100000000;
    int N, M;
    int x, y, w;
    
    while (cin >> N) { // wrapper begin

    cin >> M;
    // init
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            d[i][j] = MAX;
        }
        d[i][i] = 0;
    }
    // input
    for (int i=0; i<M; i++) {
        cin >> x >> y >> w;
        if (d[x][y] > w) {
            d[x][y] = d[y][x] = w;
        }
    }
    // Floyd
    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (d[i][k]+d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    // output
    for (int i=1; i<=N; i++) {
        cout << d[i][1];
        for (int j=2; j<=N; j++) {
            cout << " " << d[i][j];
        }
        cout << "\n";
    }

    } // wrapper end
    return 0;
}
