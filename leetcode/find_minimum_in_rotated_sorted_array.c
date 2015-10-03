#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int head, tail;
    head = nums[0];
    tail = nums[numsSize-1];
    if (numsSize <= 2) { // patch
        if (head < tail) return head;
        else return tail;
    }
    if (head < tail) return head;
    int left, right, mid;
    left = 1;
    right = numsSize-1;
    while (1) {
        mid = (left + right) / 2;
        if (nums[mid-1] > nums[mid]) break;
        if (nums[mid] > head) left = mid+1;
        else right = mid;
    }
    return nums[mid];
}


int main(int argc, char const *argv[])
{
    int a[] = {5,1,2,3,4};
    printf("min = %d\n", findMin(a, 5));
    return 0;
}
