#include <stdio.h>
#include <stdlib.h>

int maxProfit(int *prices, int pricesSize) {
    int *forward = (int *)malloc((pricesSize+1)*sizeof(int));
    int *backward = (int *)malloc((pricesSize+1)*sizeof(int));
    int i, min, max, result;
    result = 0;

    forward[pricesSize] = forward[0] = 0;
    min = prices[0];
    for (i=1; i<pricesSize; i++) {
        if (prices[i] - min < forward[i-1]) forward[i] = forward[i-1];
        else forward[i] = prices[i] - min;
        if (prices[i] < min) min = prices[i];
    }

    backward[pricesSize] = backward[pricesSize-1] = 0;
    max = prices[pricesSize-1];
    for (i=pricesSize-2; i>=0; i--) {
        if (max - prices[i] < backward[i+1]) backward[i] = backward[i+1];
        else backward[i] = max - prices[i];
        if (max < prices[i]) max = prices[i];
    }

    for (i=0; i<pricesSize; i++) {
        if (forward[i] > result) result = forward[i];
        if (backward[i+1] > result) result = backward[i+1];
        if (forward[i] + backward[i+1] > result) {
            result = forward[i] + backward[i+1];
        }
    }
    return result;
}


int main(int argc, char *argv[]) {
    int a[] = {1, 2};
    printf("%d\n", maxProfit(a, 2));
}
