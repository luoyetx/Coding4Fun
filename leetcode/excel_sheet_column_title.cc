#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string convertToTitle(int n) {
        // n >= 1
        int len = 0, tmp;
        char a[10];
        a[9] = '\0';
        while (n > 0) {
            tmp = n % 26;
            if (tmp == 0) {
                n -= 26;
                tmp = 26;
            }
            a[8-len] = tmp + 'A' - 1;
            ++len;
            n /= 26;
        }
        return string(a+9-len);
    }
};


int main(int argc, char **argv) {
    Solution s;
    cout << "1: " << s.convertToTitle(1) << endl;
    cout << "10: " << s.convertToTitle(10) << endl;
    cout << "100: " << s.convertToTitle(100) << endl;
    return 0;
}
