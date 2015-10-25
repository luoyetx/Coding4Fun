#include <cstdio>
#include <string>
#include <limits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int length = str.length();
        if (length == 0) return 0;
        int starter = 0;
        while (str[starter] == ' ') starter++;
        int sign = 1;
        if (str[starter] == '+') {
            starter++;
            sign = 1;
        }
        else if (str[starter] == '-') {
            starter++;
            sign = -1;
        }
        double res = 0;
        for (int i=starter; i<length; i++) {
            if (str[i] < '0' || str[i] > '9') break;
            if (sign == 1) {
                res = 10*res + str[i] - '0';
                if (res > numeric_limits<int>::max())
                    return numeric_limits<int>::max();
            } else {
                res = 10*res - (str[i] - '0');
                if (res < numeric_limits<int>::min())
                    return numeric_limits<int>::min();
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "-2147483648";
    printf("%s is %d\n", str.c_str(), s.myAtoi(str));
    return 0;
}
