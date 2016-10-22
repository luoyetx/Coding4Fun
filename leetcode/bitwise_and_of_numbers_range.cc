#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    int res = -1;
    if (m == n) return m;
    if (m % 2 == 1) {
      res = m;
      m++;
    }
    if (n % 2 == 1) {
      if (res == -1) res = n;
      else res &= n;
      n--;
    }
    res &= 2 * rangeBitwiseAnd(m / 2, n / 2);
    return res;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  int m = 5;
  int n = 70;
  cout << "output: " << s.rangeBitwiseAnd(5, 70) << endl;
  int res = m;
  for (int i = m; i < n; i++) {
    res &= i;
  }
  cout << "real: " << res << endl;
  return 0;
}
