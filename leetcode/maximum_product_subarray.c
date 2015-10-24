#include <stdio.h>
#include <stdlib.h>

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

int maxProduct(int* nums, int numsSize) {
    int* f = (int*)malloc(numsSize*sizeof(int));
    int* g = (int*)malloc(numsSize*sizeof(int));

    int m;
    m = f[0] = g[0] = nums[0];

    int i;
    for (i=1; i<numsSize; i++) {
        int a = f[i-1]*nums[i];
        int b = g[i-1]*nums[i];
        int c = nums[i];
        f[i] = max(max(a, b), c);
        g[i] = min(min(a, b), c);
        if (f[i] > m) m = f[i];
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
