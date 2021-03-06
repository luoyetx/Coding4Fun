#include <cstdio>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> counter;
        const int length = nums.size();
        const int th = length / 2;
        map<int, int>::iterator it;
        for (int i=0; i<length; i++) {
            it = counter.find(nums[i]);
            if (it == counter.end()) {
                counter.insert(pair<int, int>(nums[i], 1));
            }
            else {
                it->second++;
            }
        }
        for (auto it=counter.cbegin(); it!=counter.cend(); it++) {
            if (it->second > th) {
                return it->first;
            }
        }
        return 0;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> a{1,2,3,2,2,2};
    printf("majority is %d\n", s.majorityElement(a));
    return 0;
}
