class Solution(object):
  # @param n, an integer
  # @return an integer
  def climbStairs(self, n):
    x = y = 1
    while n > 1:
      temp = x + y
      x = y
      y = temp
      n = n - 1
    return y


if __name__ == '__main__':
  sol = Solution()
  print sol.climbStairs(3)
