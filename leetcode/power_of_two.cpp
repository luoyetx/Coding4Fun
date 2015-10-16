#include <cstdio>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int remain;
        if (n <= 0) {
            return false;
        }
        while (n > 0) {
            remain = n % 2;
            n /= 2;
            if (n != 0 && remain != 0) {
                return false;
            }
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    int n = (1<<10) - 1;
    printf("%d is Power of 2 ? %d\n", n, s.isPowerOfTwo(n));
    return 0;
}
