/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public int minDepth(TreeNode root) {
        if (null == root) {
            return 0;
        }
        else {
            if (root.left == null) return minDepth(root.right)+1;
            if (null == root.right) return minDepth(root.left)+1;
            int l = minDepth(root.left) + 1;
            int r = minDepth(root.right) + 1;
            return (l < r) ? l : r;
        }
    }
}

public class minimum_depth_of_binary_tree {
    public static void main(String[] args) {
        Solution s = new Solution();
        TreeNode n = new TreeNode(1);
        TreeNode nl = new TreeNode(2);
        TreeNode nr = new TreeNode(3);
        TreeNode nll = new TreeNode(4);
        n.left = nl;
        n.right = nr;
        nl.left = nll;
        System.out.println(s.minDepth(n));
    }
}
