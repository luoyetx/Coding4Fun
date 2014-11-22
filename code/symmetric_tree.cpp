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

// Ҫ����������Ƿ��ǶԳƵģ����Դ����ı�������
// ���������α������ֱ��ǣ��������ң��ͣ������ң���
// ������������Ľ��������ͬ����������ǶԳƵ� 
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
	// �������� 
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
