#include <stdio.h>

void sortColors(int* nums, int numsSize) {
    int r, g, b;
    r = g = b = 0;
    int i;
    for (i=0; i<numsSize; i++) {
        switch (nums[i]) {
        case 0:
            r++;
            break;
        case 1:
            g++;
            break;
        case 2:
            b++;
            break;
        }
    }
    int start = 0;
    for (i=start; i<start+r; i++) nums[i] = 0;
    start += r;
    for (i=start; i<start+g; i++) nums[i] = 1;
    start += g;
    for (i=start; i<start+b; i++) nums[i] = 2;
}

int main(int argc, char const *argv[])
{
    int a[] = {0,1,2,2,1,0};
    sortColors(a, 6);
    int i;
    for (i=0; i<6; i++) {
        printf("%d \n", a[i]);
    }
    return 0;
}