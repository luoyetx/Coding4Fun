#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int nthUglyNumber(int n) {
    int *nums = (int*)malloc(n*sizeof(int));
    int i2, i3, i5;
    i2 = i3 = i5 = 0;
    int i;
    nums[0] = 1;
    for (i=1; i<n; i++) {
        int m2 = nums[i2] * 2;
        int m3 = nums[i3] * 3;
        int m5 = nums[i5] * 5;
        int min = m2;
        if (m3 < min) min = m3;
        if (m5 < min) min = m5;
        if (min == m2) i2++;
        if (min == m3) i3++;
        if (min == m5) i5++;
        nums[i] = min;
    }
    int res = nums[n-1];
    free(nums);
    return res;
}


int main(int argc, char const *argv[])
{
    int nth = 1600;
    printf("%dth = %d\n", nth, nthUglyNumber(nth));
    return 0;
}
