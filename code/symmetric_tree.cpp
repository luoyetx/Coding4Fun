/**
 * symmetric tree @ leetcode.com
 */

#include <iostream>
#include <vector>
using namespace std;

#define NULL_VAL -1

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 要考虑这棵树是否是对称的，可以从树的遍历着手
// 对树做两次遍历，分别是（根，左，右）和（根，右，左）
// 如果两个遍历的结果序列相同，则这棵树是对称的 
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        root_left_right.clear();
        root_right_left.clear();
        dfs_rlr(root);
        dfs_rrl(root);
        bool result = true;
        for (int i=0; i<root_left_right.size(); i++) {
        	if (root_right_left[i] != root_left_right[i]) {
        		result = false;
        		break;
        	}
        }
        return result;
    }
    
    void dfs_rlr(TreeNode* root) {
    	if (root == NULL) {
    		root_left_right.push_back(NULL_VAL);
    		return;
    	}
    	root_left_right.push_back(root->val);
    	dfs_rlr(root->left);
    	dfs_rlr(root->right);
    }
    
    void dfs_rrl(TreeNode* root) {
    	if (root == NULL) {
    		root_right_left.push_back(NULL_VAL);
    		return;
    	}
    	root_right_left.push_back(root->val);
    	dfs_rrl(root->right);
    	dfs_rrl(root->left);
    }

private:
	// 遍历序列 
	vector<int> root_left_right;
	vector<int> root_right_left;
};

// test
int main(int argc, char* argv[])
{
	Solution s;
	TreeNode r(1), rl(2), rr(2), rll(3), rrr(3);
	r.left = &rl; r.right = &rr;
	rl.left = &rll; rr.right = &rrr;
	// test1
	bool result = s.isSymmetric(&r);
	cout << "Test1::the result is " << result << endl;
	// test2
	rrr.val = 4;
	result = s.isSymmetric(&r);
	cout << "Test2::the result is " << result << endl;
	// test3
	rrr.val = 3;
	TreeNode rlr(4);
	rl.right = &rlr;
	result = s.isSymmetric(&r);
	cout << "Test3::the result is " << result << endl;
	// test4
	r.right = NULL;
	result = s.isSymmetric(&r);
	cout << "Test4::the result is " << result << endl;
	return 0;
}
