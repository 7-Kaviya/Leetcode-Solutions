/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* intersect(int* nums1, int nums1Size,
               int* nums2, int nums2Size,
               int* returnSize) {

    int* freq = (int*)calloc(2001, sizeof(int));
    int* result = (int*)malloc(nums2Size * sizeof(int));
    int j = 0;

    // Count the frequency of elements in nums1
    for (int i = 0; i < nums1Size; i++) {
        freq[nums1[i] + 1000]++;
    }

    // Find common elements using their frequencies
    for (int i = 0; i < nums2Size; i++) {
        int index = nums2[i] + 1000;

        if (freq[index] > 0) {
            result[j++] = nums2[i];
            freq[index]--;
        }
    }

    free(freq);

    *returnSize = j;
    return result;
}