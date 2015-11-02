#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(sizeof(int)*numsSize);
    res[0] = 1;
    int i;
    for (i=1; i<numsSize; i++) {
        res[i] = res[i-1]*nums[i-1];
    }
    int p = 1;
    for (i=numsSize-1; i>=0; i--) {
        res[i] *= p;
        p *= nums[i];
    }
    *returnSize = numsSize;
    return res;
}


int main(int argc, char* argv[]) {
    int a[] = {1,2,3,4};
    int len, i;
    int* res = productExceptSelf(a, 4, &len);
    for (i=0; i<len; i++) {
        printf("%d ", res[i]);
    }
    free(res);
    return 0;
}
