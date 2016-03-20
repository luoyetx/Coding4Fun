#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

#define max(x, y) (((x)<(y))?(y):(x))
void rob_node(struct TreeNode *root, int *f, int *g) {
  *f = *g = 0;
  if (!root) return;

  int lf, lg, rf, rg;
  rob_node(root->left, &lf, &lg);
  rob_node(root->right, &rf, &rg);

  *f = root->val + lg + rg;
  *g = max(lf, lg) + max(rf, rg);
  return;
}

int rob(struct TreeNode* root) {
  int f, g;
  rob_node(root, &f, &g);
  if (f > g) return f;
  else return g;
}

int main(int argc, char *argv[]) {
  TreeNode n1, n2, n3, n4, n5;
  n1.val = 3;
  n2.val = 2;
  n3.val = 3;
  n4.val = 3;
  n5.val = 1;
  n1.left = &n2;
  n1.right = &n3;
  n2.left = NULL;
  n2.right = &n4;
  n3.left = NULL;
  n3.right = &n5;
  n4.left = n4.right = n5.left = n5.right = NULL;

  int v = rob(&n1);
  printf("value = %d\n", v);
  return 0;
}
