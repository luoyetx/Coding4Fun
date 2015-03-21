#include <cassert>
#include <iostream>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode *t = root;
        while (t) {
            path_.push(t);
            t = t->left;
        }
    }

    bool hasNext() {
        if (path_.empty()) {
            return false;
        }
        else {
            return true;
        }
    }

    int next() {
        assert(!path_.empty());
        TreeNode *res = path_.top();
        TreeNode *t = path_.top();
        if (t->right) {
            t = t->right;
            while (t->left) {
                path_.push(t);
                t = t->left;
            }
            path_.push(t);
            return res->val;
        }
        path_.pop();
        while (!path_.empty() && path_.top()->right == t) {
            t = path_.top();
            path_.pop();
        }
        return res->val;
    }

private:
    stack<TreeNode*> path_;
};


int main(int argc, char *argv[]) {
    TreeNode root(3);
    TreeNode rl(1);
    TreeNode rlr(2);
    root.left = &rl;
    rl.right = &rlr;
    BSTIterator iter(&root);
    while (iter.hasNext()) {
        cout << iter.next() << endl;
    }
    return 0;
}
