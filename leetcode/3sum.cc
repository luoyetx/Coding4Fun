#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<int> res_one;
        int N = nums.size();
        for (int i=0; i<N; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j=i+1; j<N; j++) {
                if (nums[i]+nums[j] > 0) break;
                if (j>i+1 && nums[j] == nums[j-1]) continue;
                for (int k=j+1; k<N; k++) {
                    if (k>j+1 && nums[k] == nums[k-1]) continue;
                    int tmp = nums[i]+nums[j]+nums[k];
                    if (tmp == 0) {
                        res_one.clear();
                        res_one.push_back(nums[i]);
                        res_one.push_back(nums[j]);
                        res_one.push_back(nums[k]);
                        result.push_back(res_one);
                    }
                    else if (tmp > 0) {
                        break;
                    }
                }
            }
        }
        return result;
    }
};


int main(int argc, char *argv[]) {
    vector<int> sample{-1, 0, 1, 2, -1, -4};
    vector<vector<int> > result;
    Solution s;
    result = s.threeSum(sample);
    cout << result.size() << endl;
    return 0;
}