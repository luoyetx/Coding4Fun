#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxRotateFunction(vector<int>& A) {
    int sum1, part, sum2, res;
    sum1 = part = sum2 = res = 0;
    int n = A.size();
    if (n == 0) return 0;
    for (int i = 0; i < n; i++) {
      sum1 += A[i];
      res += i * A[i];
    }
    int last = res;
    sum1 -= A[n-1];
    sum2 += 0;
    for (int i = n-1; i >= 1; i--) {
      last = last + sum1 - (n-1)*A[i] + sum2;
      sum1 -= A[i-1];
      sum2 += A[i];
      if (last > res) res = last;
    }
    return res;
  }
};


int main(int argc, char* argv[]) {
  vector<int> a = {4, 3, 2, 6};
  Solution s;
  int res = s.maxRotateFunction(a);
  cout << res << endl;
  return 0;
}
