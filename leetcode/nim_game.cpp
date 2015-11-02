#include <cstdio>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n%4 != 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n = 8;
    printf("%d can win, value = %d\n", n, s.canWinNim(n));
    return 0;
}
