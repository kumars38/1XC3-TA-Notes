#include <stdio.h>
#include <stdbool.h>

// assume nums is already sorted
bool twoSum(const int nums[], const int size, const int target) {
    int i=0;
    int j=size-1;
    while (i<j) {
        int sum = nums[i]+nums[j];
        if (sum == target)
            return true;
        if (sum < target) {
            i++;
        }
        else { // sum > target
            j--;
        }
    }
    return false;
}

int main() {
    int nums[] = {2,7,11,15};
    int size = sizeof(nums)/sizeof(nums[0]);
    int target=18;
    bool res = twoSum(nums,size,target);
    printf("Target is achievable: %s\n", res ? "true" : "false");
}

// If nums was not sorted:
    // store every num in hashmap - O(n)
    // iterate through nums, if map(target-nums[i]) in map (and not dupe), return true - O(n)
    // else return false
// Since nums is sorted:
    // Use two-pointer approach