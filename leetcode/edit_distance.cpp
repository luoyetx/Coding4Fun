#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    vector<vector<int> > f;
    f.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      f[i].resize(m + 1);
    }
    for (int i = 0; i <= n; i++) {
      f[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
      f[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int val = std::min(f[i-1][j-1], std::min(f[i-1][j], f[i][j-1])) + 1;
        if (i < j) {
          val = std::min(f[i][i] + j-i, val);
        }
        if (i > j) {
          val = std::min(f[j][j] + i-j, val);
        }
        if (word1[i-1] == word2[j-1]) {
          val = std::min(f[i-1][j-1], val);
        }
        f[i][j] = val;
      }
    }
    return f[n][m];
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  int distance = s.minDistance("sea", "ate");
  cout << distance << endl;
  return 0;
}
