#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        nums.push_back(numeric_limits<int>::max());
        int length = nums.size();
        int start = 0;
        int end;
        int i = 1;
        vector<string> res;
        char buff[256];
        while (i < length) {
            while (i<length && (nums[i]==nums[i-1]+1)) i++;
            end = i-1;
            if (start == end) {
                sprintf(buff, "%d", nums[start]);
                res.push_back(string(buff));
            } else {
                sprintf(buff, "%d->%d", nums[start], nums[end]);
                res.push_back(string(buff));
            }
            start = i;
            i++;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> res;
    vector<int> nums{0,1,2,4,5,7};
    res = s.summaryRanges(nums);
    for (int i=0; i<res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}