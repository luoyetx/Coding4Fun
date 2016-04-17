#include <stdio.h>

int search(int* nums, int numsSize, int target) {
  int idx = -1;
  if (numsSize < 10) {
    int i;
    for (i=0; i<numsSize; i++) {
      if (nums[i] == target) idx = i;
    }
    return idx;
  }

  int left, right, middle;
  int sep;
  if (nums[0] < nums[numsSize-1]) {
    left = -1; right = 0;
    sep = 0;
  } else {
    left = 0; right = numsSize-1;
    while (right != left+1) {
      middle = (left + right) / 2;
      if (nums[middle] < nums[middle-1]) {
        left = middle-1;
        right = middle;
      } else {
        // top
        if (nums[middle] > nums[0])
          left = middle;
        else
          right = middle - 1;
      }
    }
    sep = right;
  }

  // first half, [0, sep-1]
  if (sep > 0) {
    left = 0; right = sep-1;
    if (nums[left] > target || nums[right] < target) {
      idx = -1;
    } else {
      while (left < right) {
        middle = (left + right) / 2;
        if (nums[middle] == target) return middle;
        if (nums[middle] < target) left = middle+1;
        else right = middle-1;
      }
      if (nums[left] == target) return left;
    }
  }
  if (idx != -1) return idx;
  // second half, [seq, numsSize]
  left = sep; right = numsSize-1;
  if (nums[left] > target || nums[right] < target)
    return -1;
  while (left < right) {
    middle = (left + right) / 2;
    if (nums[middle] == target) return middle;
    if (nums[middle] < target) left = middle+1;
    else right = middle-1;
  }
  if (nums[left] == target) return left;
  else return -1;
}

int main(int argc, char* argv[]) {
  int nums[] = {279,284,285,287,288,296,2,8,10,11,12,13,14,19,20,22,25,26,27,28,29,33,37,39,42,43,47,48,49,50,57,62,63,66,68,69,71,73,74,77,78,79,85,89,92,94,99,111,113,117,120,122,125,134,145,152,155,157,160,161,167,168,181,182,188,189,190,194,199,201,204,208,213,220,223,225,226,227,231,237,240,242,247,254,259,260,261,264,267,271,275};
  int idx = search(nums, sizeof(nums)/4, 298);
  printf("idx = %d\n", idx);
  return 0;
}
