#include <stdio.h>

int minCostClimbingStairs(int cost[], int costSize) {
    if (costSize == 0) return 0;       // no stairs, no cost
    if (costSize == 1) return cost[0]; // cost = this step
    
    // Store cumulative costs to get to 2nd last step and last step
    int prev2 = cost[0];
    int prev1 = cost[1];
    
    // Starting from step 2
    for (int i = 2; i < costSize; i++) {
        // Add cost of current step (cost[i]) to the path of minimal cost
        int current = ((prev1 < prev2) ? prev1 : prev2) + cost[i];
        prev2 = prev1;
        prev1 = current;
    }
    return (prev1 < prev2) ? prev1 : prev2;
}

int main() {
    // Example
    // int cost[] = {8, 12, 20};
    int cost[] = {8, 12, 20, 25, 2, 1};
    int costSize = sizeof(cost) / sizeof(cost[0]);
    int res = minCostClimbingStairs(cost, costSize);
    printf("Min cost: %d\n", res); // Correctly outputs 12
}