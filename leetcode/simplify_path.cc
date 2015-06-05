#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    string simplifyPath(string path) {
        vector<string> pathStack;
        vector<string> tokens;
        
        // parse
        string token = "";
        for (int i=0; i<path.length(); i++) {
            if (path[i] != '/') {
                token += path[i];
            }
            else {
                if (token != "") tokens.push_back(token);
                token = "";
            }
        }
        if (token != "") tokens.push_back(token);

        // simplify by stack
        for (int i=0; i<tokens.size(); i++) {
            if (tokens[i] == ".") {
                continue;
            } else if (tokens[i] == "..") {
                if (pathStack.size() > 0) pathStack.pop_back();
            } else {
                pathStack.push_back(tokens[i]);
            }
        }

        // generate path
        string result = "";
        if (pathStack.size() == 0) {
            result = "/";
        }
        else {
            for (int i=0; i<pathStack.size(); i++) {
                result += "/" + pathStack[i];
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Solution s;
    string testPath;
    testPath = "/home/";
    cout << testPath << " ==> " << s.simplifyPath(testPath) << endl;
    testPath = "/a/./b/../../c/";
    cout << testPath << " ==> " << s.simplifyPath(testPath) << endl;
    testPath = "/a/../../../";
    cout << testPath << " ==> " << s.simplifyPath(testPath) << endl;
    return 0;
}
