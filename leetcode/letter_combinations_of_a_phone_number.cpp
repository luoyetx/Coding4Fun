#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // "23..."
        // "" -> "a", "b", "c"
        //    -> "ad", "bd", "cd", "ae", "af", "be", "bf", "ce", "cf"
        //    -> ...
        vector<string> result;
        char d[][10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        // start up
        result.push_back("");
        // not support c++11 ?
        for (int i=0; i<digits.size(); i++) {
            int num = digits[i] - '0';
            int l = result.size();
            for (int j=0; j<l; j++) {
                string _ = result[j];
                result[j] = _+d[num][0];
                for (int k=1; k<strlen(d[num]); k++) {
                    result.push_back(_+d[num][k]);
                }
            }
        }
        return result;
    }
};


int main(int argc, char* argv[]) {
    Solution s;
    auto r = s.letterCombinations("23");
    for_each(r.begin(), r.end(), [](string& s){
                cout << s << "\n";
            });
    return 0;
}
