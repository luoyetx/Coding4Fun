#include <stdio.h>
#include <stdlib.h>

#define max(x, y) ((x)>(y)?(x):(y))

int rob(int* nums, int numsSize) {
    int* f = (int*)malloc(numsSize*sizeof(int));
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    int res;
    // not rob the last one
    f[0] = nums[0];
    f[1] = max(nums[0], nums[1]);
    int i;
    for (i=2; i<numsSize-1; i++) {
        f[i] = max(f[i-2] + nums[i], f[i-1]);
    }
    res = f[numsSize-2];

    // not rob the first
    f[1] = nums[1];
    f[2] = max(nums[1], nums[2]);
    for (i=3; i<numsSize; i++) {
        f[i] = max(f[i-2] + nums[i], f[i-1]);
    }
    if (f[numsSize-1] > res) res = f[numsSize-1];

    return res;
}

int main(int argc, char const *argv[])
{
    int nums[] = {2,1,1,2};
    printf("%d\n", rob(nums, 4));
    return 0;
}
