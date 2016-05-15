#include <vector>

using std::vector;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int> > pathSum(TreeNode* root, int sum) {
    vector<vector<int> > res;
    vector<int> current;

    if (!root) return res;

    go(root, res, current, sum);

    return res;
  }

  void go(TreeNode* root, vector<vector<int> >& res, vector<int>& current, int residual) {
    current.push_back(root->val);
    int residual_ = residual - root->val;
    if (residual_ == 0 && !root->left && !root->right) {
      res.push_back(current);
      current.pop_back();
      return;
    }

    if (root->left) go(root->left, res, current, residual_);
    if (root->right) go(root->right, res, current, residual_);

    current.pop_back();
    return;
  }
};
