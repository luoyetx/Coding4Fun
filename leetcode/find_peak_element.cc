#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int l, m, r;
    l = 0; r = nums.size() - 1;
    while (1) {
      if (r - l <= 2) {
        int mm = nums[l];
        int mm_i = l;
        for (int i=l; i<=r; i++) {
          if (nums[i] > mm) {
            mm = nums[i];
            mm_i = i;
          }
        }
        return mm_i;
      }

      m = (l + r) >> 1;
      if (m == 0 || m == nums.size()-1) return m;
      if (nums[m] > nums[m-1] && nums[m] > nums[m+1]) {
        // find the peak
        return m;
      }
      if (nums[m] < nums[m+1]) l = m + 1;
      else r = m - 1;
    }
    return 0;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> nums = {1, 2, 3, 1};
  cout << s.findPeakElement(nums) << endl;
}
