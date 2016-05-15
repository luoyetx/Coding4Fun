struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int sum) {
  if (root == NULL) return false;

  int residual = sum - root->val;
  if (!root->left && !root->right && residual == 0) return true;

  if (root->left && hasPathSum(root->left, residual)) return true;
  if (root->right && hasPathSum(root->right, residual)) return true;
  return false;
}
