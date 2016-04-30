#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    if (nums.size() <= 0) return 0;

    int l, r, len_min, sum;
    l = r = 0;
    len_min = nums.size() + 1;
    sum = 0;

    while (r < nums.size()) {
      sum += nums[r];
      while (l < r && sum-nums[l] >= s) {
        sum -= nums[l];
        l++;
      }
      if (sum >= s && r-l+1 < len_min) len_min = r-l+1;
      r++;
    }

    if (len_min == nums.size()+1) len_min = 0;
    return len_min;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> nums = {2,3,1,2,4,30};
  cout << s.minSubArrayLen(7, nums) << endl;
  return 0;
}
