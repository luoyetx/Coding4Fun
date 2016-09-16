#include <iostream>

using namespace std;

class Solution {
public:
  int integerReplacement(int n) {
    int ans = 0;
    unsigned int m = n;
    while (m != 1) {
      if (m % 2 == 0) {
        m /= 2;
        ans += 1;
      }
      else {
        int p1 = (m + 1) / 2;
        int p2 = (m - 1) / 2;
        if (p2 != 1 && p2 % 2 == 1) {
          m = p1;
        }
        else {
          m = p2;
        }
        ans += 2;
      }
    }
    return ans;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  cout << s.integerReplacement(2147483647) << endl;
  return 0;
}
