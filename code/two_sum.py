class Solution:
  # @return a tuple, (index1, index2)
  def twoSum(self, num, target):
    numWithIndex = [[o, i] for i, o in enumerate(num)]
    numWithIndex.sort()
    self.num = [o[0] for o in numWithIndex]
    self.target = target
    for index1 in xrange(len(self.num)-1):
      index2 = self.binSearch(index1)
      if index2 is not None:
        o1 = numWithIndex[index1][1]+1
        o2 = numWithIndex[index2][1]+1
        return (o1, o2) if o1 < o2 else (o2, o1)

  # @return an index for solution if any or None
  def binSearch(self, index):
    r = len(self.num) - 1
    l = index + 1
    while (l <= r):
      mid = (l+r) / 2
      o = self.num[index] + self.num[mid]
      if o == self.target:
        return mid
      elif o < self.target:
        l = mid + 1
      else:
        r = mid - 1
    return None

if __name__ == '__main__':
  sol = Solution()
  print sol.twoSum([2, 15, 7, 15], 9)
  print sol.twoSum([3,2,4], 6)
