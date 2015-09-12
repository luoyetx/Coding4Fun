#include <stdio.h>

inline static void swap(int* nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int firstMissingPositive(int* nums, int numsSize) {
    int i;
    for (i=0; i<numsSize; i++) {
        while (nums[i]>0 && nums[i]<=numsSize && nums[i] != i+1) {
            if (nums[i] == nums[nums[i]-1]) break;
            swap(nums, i, nums[i]-1);
        }
    }
    for (i=0; i<numsSize; i++) {
        if (nums[i] != i+1) {
            return i+1;
        }
    }
    return nums[numsSize-1]+1;
}

int main(int argc, char* argv[]) {
    int a[] = {1, 1};
    int res = firstMissingPositive(a, 4);
    printf("%d\n", res);
    return 0;
}
