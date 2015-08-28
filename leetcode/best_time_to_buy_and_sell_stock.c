#include <stdio.h>

int maxProfit(int *prices, int pricesSize) {
    int result = 0;
    int min = prices[0];
    for (int i=1; i<pricesSize; i++) {
        if (prices[i] - min > result) {
            result = prices[i] - min;
        }
        min = (prices[i] < min) ? prices[i] : min;
    }
    return result;
}


int main(int argc, char *argv[]) {
    int a[] = {4,3,2,1};
    printf("%d\n", maxProfit(a, 4));
}
