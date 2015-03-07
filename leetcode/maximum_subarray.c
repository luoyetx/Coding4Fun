#include <stdio.h>

#define NINF -1000000

int maxSubArray(int A[], int n)
{
    int tmp, res;
    tmp = 0;
    res = NINF;
    int i;
    for (i=0; i<n; i++) {
        tmp += A[i];
        if (tmp > res) {
            res = tmp;
        }
        if (tmp < 0) {
            tmp = 0;
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    // test 1
    int a[10] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("%d\n", maxSubArray(a, 9));
    return 0;
}
