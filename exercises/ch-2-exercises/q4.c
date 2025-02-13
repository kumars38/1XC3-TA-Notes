#include <stdio.h>

int minCostClimbingStairs(int* cost, int costSize) {
    // Try starting from step 0
    int startFromZero = cost[0];
    if (costSize >= 3) {
        // If taking one step from 0, pay cost[1]
        int oneStep = startFromZero + cost[1];
        // If taking two steps from 0, pay cost[2]
        int twoSteps = startFromZero + cost[2];
        
        // Choose the cheaper option
        if (oneStep < twoSteps) {
            startFromZero = oneStep;
        } else {
            startFromZero = twoSteps;
        }
    }
    
    // Try starting from step 1
    int startFromOne = cost[1];
    if (costSize >= 4) {
        // If at step 1, we can either take:
        // one more step to step 2 (cost[2])
        // or two more steps to step 3 (cost[3])
        if (cost[2] < cost[3]) {
            startFromOne += cost[2];
        } else {
            startFromOne += cost[3];
        }
    }
    
    // Return the minimum of the two possible starts
    if (startFromZero < startFromOne) {
        return startFromZero;
    } else {
        return startFromOne;
    }
}

int main() {
    // Test case from the example
    int cost[] = {8, 12, 20};
    int size = 3; //sizeof(cost) / sizeof(cost[0]);
    
    // Call function and print result
    printf("Minimum cost: %d\n", minCostClimbingStairs(cost, size));
    
    return 0;
}