#include <stdio.h>

void twoSum(int arr[], int n, int target) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Target= sum of arr[%d] and arr[%d]\n", i, j);
                return;
            }
        }
    }
    printf("No pair found\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int target = 10;
    int size = sizeof(arr) / sizeof(int);
    
    twoSum(arr, size, target);
    return 0;
}