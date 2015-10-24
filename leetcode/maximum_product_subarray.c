#include <stdio.h>
#include <stdlib.h>

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

int maxProduct(int* nums, int numsSize) {
    int i, m, f, g;
    m = f = g = nums[0];
    for (i=1; i<numsSize; i++) {
        int a = f*nums[i];
        int b = g*nums[i];
        int c = nums[i];
        f = max(max(a, b), c);
        g = min(min(a, b), c);
        if (f > m) m = f;
    }
    return m;
}


int main(int argc, char const *argv[])
{
    int a[] = {2, 3, -2, 4};
    int res = maxProduct(a, 4);
    printf("res = %d\n", res);
    return 0;
}
