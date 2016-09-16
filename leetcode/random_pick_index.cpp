#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  struct Element {
    int val;
    int index;
  };
  vector<Element> elements;

  Solution(vector<int> nums) {
    int n = nums.size();
    elements.resize(n);
    for (int i = 0; i < n; i++) {
      elements[i].val = nums[i];
      elements[i].index = i;
    }
    sort(elements.begin(), elements.end(), Compare);
  }

  static bool Compare(const Element& x, const Element& y) {
    if (x.val < y.val) return true;
    else return false;
  }

  int pick(int target) {
    int left = -1;
    int right = elements.size();
    while (left != right - 1) {
      int mid = (left + right) / 2;
      int val = elements[mid].val;
      if (val >= target) {
        right = mid;
      }
      else {
        left = mid;
      }
    }
    int rleft = left + 1;
    left = -1;
    right = elements.size();
    while (left != right - 1) {
      int mid = (left + right) / 2;
      int val = elements[mid].val;
      if (val <= target) {
        left = mid;
      }
      else {
        right = mid;
      }
    }
    int rright = right - 1;
    int res = rand() % (rright - rleft + 1) + rleft;
    return elements[res].index;
  }
};

int main(int argc, char* argv[]) {
  vector<int> nums = { 2, 2, 4, 4, 3, 3 };
  Solution s(nums);
  cout << s.pick(4) << endl;
  return 0;
}
