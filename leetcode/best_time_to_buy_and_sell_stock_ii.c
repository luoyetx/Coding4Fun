#include <stdio.h>


int maxProfit(int *prices, int pricesSize) {
    int result = 0;
    for (int i=1; i<pricesSize; i++) {
        if (prices[i]-prices[i-1] > 0)
            result += prices[i] - prices[i-1];
    }
    return result;
}


int main(int argc, char *argv[]) {
    int a[] = {3,4,1,2};
    printf("%d\n", maxProfit(a, 4));
}
