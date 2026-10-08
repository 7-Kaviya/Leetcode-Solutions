/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** summaryRanges(int* nums, int numsSize, int* returnSize) {

    // Allocate space for result
    char** result = (char**)malloc(numsSize * sizeof(char*));

    *returnSize = 0;

    if (numsSize == 0) {
        return result;
    }

    int start = nums[0];

    for (int i = 1; i <= numsSize; i++) {

        // End of a range
        if (i == numsSize || nums[i] != nums[i - 1] + 1) {

            result[*returnSize] = (char*)malloc(50 * sizeof(char));

            if (start == nums[i - 1]) {
                sprintf(result[*returnSize], "%d", start);
            }
            else {
                sprintf(result[*returnSize], "%d->%d",
                        start, nums[i - 1]);
            }

            (*returnSize)++;

            // Start next range
            if (i < numsSize) {
                start = nums[i];
            }
        }
    }

    return result;
}