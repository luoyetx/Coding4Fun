void merge(int* nums1, int m, int* nums2, int n) {
  int i, j, k;
  i = m - 1;
  j = n - 1;
  k = m + n -1;
  while (k >= 0) {
    if (i < 0) {
      nums1[k] = nums2[j];
      j--;
      k--;
    }
    else if (j < 0) {
      nums1[k] = nums1[i];
      i--;
      k--;
    }
    else {
      if (nums1[i] > nums2[j]) {
        nums1[k] = nums1[i];
        i--;
        k--;
      }
      else {
        nums1[k] = nums2[j];
        j--;
        k--;
      }
    }
  }
}
