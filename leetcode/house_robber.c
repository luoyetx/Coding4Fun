#include <stdio.h>
#include <stdlib.h>

#define max(x, y) ((x)>(y)?(x):(y))

int rob(int* nums, int numsSize) {
    int* f = (int*)malloc(numsSize*sizeof(int));
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    f[0] = nums[0];
    f[1] = max(nums[0], nums[1]);
    int i;
    for (i=2; i<numsSize; i++) {
        f[i] = max(f[i-2] + nums[i], f[i-1]);
    }
    return f[numsSize-1];
}

int main(int argc, char const *argv[])
{
    int nums[] = {2,1,2,1};
    printf("%d\n", rob(nums, 4));
    return 0;
}