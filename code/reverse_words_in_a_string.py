class Solution:
  # @param s, a string
  # @return a string
  def reverseWords(self, s):
    words = s.split(' ')
    # remove ''
    words = [rv for rv in words if rv != '']
    words.reverse()
    return ' '.join(words)


if __name__ == '__main__':
  sol = Solution()
  print sol.reverseWords('the sky is blue')
