#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

#define INC(x) do { \
    ++x[0]; \
    int i = 0; \
    while (x[i] == 2) { \
        x[i] = 0; ++x[i+1]; \
        ++i; \
    } \
} while(0)

using namespace std;

class Solution {
  public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<int> set;
        vector<vector<int> > result;
        
        sort(nums.begin(), nums.end());

        int a[20];
        memset(a, 0, sizeof(int)*20);
        int length = pow(2, nums.size());
        for (int i=0; i<length; ++i) {
            INC(a);
            set.clear();
            for (int j=0; j<nums.size(); ++j) {
                if (a[j]) set.push_back(nums[j]);
            }
            result.push_back(set);
        }

        return result;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums(3, 0);
    nums[0] = 3; nums[1] = 2; nums[2] = 1;
    
    auto result = s.subsets(nums);
    cout << "[" << endl;
    for (int i=0; i<result.size(); i++) {
        cout << "[";
        for (int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << ",";
        }
        cout << "]," << endl;
    }
    cout << "]" << endl;
    return 0;
}
