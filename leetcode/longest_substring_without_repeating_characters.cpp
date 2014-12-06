#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int length = s.length();
		int* pos = new int[length];
		int characters[256];
		for (int i = 0; i<256; i++) characters[i] = -1;

		for (int i = 0; i<length; i++) {
			pos[i] = characters[s[i]];
			characters[s[i]] = i;
		}

		int max_length = 0;

		for (int i = 0; i < length; i++) {
			int r = pos[i];
			for (int j = pos[i] + 1; j < i; j++) {
				if (r < pos[j]) {
					r = pos[j];
				}
			}
			if (i - r > max_length) {
				max_length = i - r;
			}
		}

		delete[] pos;
		return max_length;
	}
};


int main(int argc, char* argv[]) {
	Solution s;
	string str = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
	int l = s.lengthOfLongestSubstring(str);
	printf("%s is %d\n", str.c_str(), l);
	system("pause");
	return 0;
}
