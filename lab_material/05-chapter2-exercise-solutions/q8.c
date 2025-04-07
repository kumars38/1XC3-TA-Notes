#include <stdio.h>

// assumes nums is a sorted array with no duplicates
// perform iterative binary search - O(log n)
int binarySearch(const int* nums, const int numsSize, const int target) {
    int l=0;
    int r=numsSize-1;
    int mid;

    // loop until pointers are invalid (cross over)
    while (l <= r) {
        mid = (l+r)/2;
        if (nums[mid] == target)
            return mid;             // target found, return index
        if (nums[mid] < target)     // too small, search second half
            l = mid+1;
        if (nums[mid] > target)     // too large, search first half
            r = mid-1;
    }
    return -1;
}

int main() {
    int nums[] = {-2,0,3,7,12};
    int len = sizeof(nums)/sizeof(nums[0]);
    int target = 12;
    printf("Index of %d: %d\n",target,binarySearch(nums,len,target));
}