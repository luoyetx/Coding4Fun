#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int res = 1;
        int left, right;
        left = right = 0;

        for (int i=len-1; i>=0; i--) {
            f[i][i] = true;
            f[i+1][i] = true; // for j == i+1
            for (int j=i+1; j<len; j++) {
                f[i][j] = ((s[i]==s[j])&&(f[i+1][j-1]));
                if (f[i][j] && (j-i+1)>res) {
                    res = j-i+1;
                    left = i; right = j;
                }
            }
        }
        
        return s.substr(left, res);
    }

    bool f[1001][1000];
};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.longestPalindrome("a") << endl;
}
