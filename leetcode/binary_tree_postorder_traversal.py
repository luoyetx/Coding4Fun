# Definition for a  binary tree node
class TreeNode(object):
  def __init__(self, x):
    self.val = x
    self.left = None
    self.right = None


class Solution(object):
    # @param root, a tree node
    # @return a list of integers
    def postorderTraversal(self, root):
      self.index = []
      if root:
        self.travel(root)
      return self.index

    # @param root, a tree node
    def travel(self, root):
      if root.left:
        self.travel(root.left)
      if root.right:
        self.travel(root.right)
      self.index.append(root.val)


if __name__ == '__main__':
  root = TreeNode(1)
  node1 = TreeNode(2)
  node2 = TreeNode(3)
  root.right = node1
  node1.left = node2

  sol = Solution()
  print sol.postorderTraversal(root)
