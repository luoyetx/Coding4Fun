#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;


class Solution {
  public:
    bool wordBreak(string s, unordered_set<string> &wordDict) {\
        int len = s.length();
        bool *f = new bool[len];
        
        for (int i=0; i<len; i++) {
            f[i] = false;
            for (auto& mark : wordDict) {
                int j = i - mark.length() + 1;
                if (j == 0 || (j>0 && f[j-1])) {
                    if (s.substr(j, mark.length()) == mark) {
                        f[i] = true;
                        break;
                    }
                }
                else {
                    continue;
                }
            }
        }

        bool result = f[len-1];
        delete f;
        return result;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("code");

    cout << s.wordBreak("leetcode", dict) << endl;
    return 0;
}
