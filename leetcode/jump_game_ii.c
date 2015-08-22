#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int jump(int* nums, int numsSize) {
    int *steps = (int *)malloc(numsSize * sizeof(int));

    // steps_k = min{ steps_j + 1 | j<k && nums[j]>=k-j}
    steps[0] = 0;
    for (int k=1; k<numsSize; k++) {
        for (int j=0; j<k; j++) {
            if (nums[j] >= k-j) {
                steps[k] = steps[j] + 1;
                break;
            }
        }
    }

    int result = steps[numsSize-1];
    free(steps);
    return result;
}

int main(int argc, char *argv[])
{
    int test[5] = {2, 3, 1, 1, 4};
    printf("%d\n", jump(test, 5));
    return 0;
}