#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int missingNumber(int* nums, int numsSize) {

    int n = numsSize;

    // Sort the array
    qsort(nums, n, sizeof(int), compare);

    // Find the missing number
    for (int i = 0; i < n; i++) {
        if (nums[i] != i) {
            return i;
        }
    }

    return n;
}