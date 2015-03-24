#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& num) {
        TreeNode* root = buildBST(num, 0, num.size()-1);
        return root;
    }

    void free(TreeNode* root) {
        if (!root) {
            return;
        }
        free(root->left);
        free(root->right);
        delete root;
    }

private:
    TreeNode* buildBST(vector<int>& num, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(num[mid]);
        TreeNode* left_node = buildBST(num, left, mid-1);
        TreeNode* right_node = buildBST(num, mid+1, right);
        root->left = left_node;
        root->right = right_node;
        return root;
    }
};

int main(int argc, char* argv[]) {
    
    return 0;
}
