#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    vector<int> wall(n);

    wall[0] = height[0];
    for (int i=1; i<n; i++) {
      wall[i] = std::max(wall[i-1], height[i]);
    }

    wall[n-1] = std::min(wall[n-1], height[n-1]);
    for (int i=n-2; i>=0; i--) {
      wall[i] = std::min(wall[i], std::max(wall[i+1], height[i]));
    }

    int res = 0;
    for (int i=0; i<n; i++) {
      res += wall[i] - height[i];
    }

    return res;
  }
};

int main(int argc, char* argv[]) {
  vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
  Solution s;
  cout << s.trap(h) << endl;
  return 0;
}
