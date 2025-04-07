#include <stdio.h>
#include <limits.h>

// O(n)
int maxProfit(const int p[], int size) {
    int lowest = INT_MAX;
    int currMaxProfit = 0;
    for (int i=0; i<size; i++) {
        if (p[i] < lowest)
            lowest = p[i];
        if (p[i] - lowest > currMaxProfit)
            currMaxProfit = p[i] - lowest;
    }
    return currMaxProfit;
}

int main() {
    int prices[] = {8,1,6,4,7,4};
    int size = 6;
    printf("Max Profit: %d\n",maxProfit(prices, size));
}