/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* intersection(int* nums1, int nums1Size,
                  int* nums2, int nums2Size,
                  int* returnSize) {

    int* result = (int*)malloc(nums2Size * sizeof(int));
    int j = 0;

    // Create a copy of nums1 and sort it
    int* arr = (int*)malloc(nums1Size * sizeof(int));

    for (int i = 0; i < nums1Size; i++) {
        arr[i] = nums1[i];
    }

    // Sort arr using bubble sort
    for (int i = 0; i < nums1Size - 1; i++) {
        for (int k = 0; k < nums1Size - i - 1; k++) {
            if (arr[k] > arr[k + 1]) {
                int temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }

    // Find common elements, avoiding duplicates
    for (int i = 0; i < nums2Size; i++) {
        int left = 0, right = nums1Size - 1;
        int found = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == nums2[i]) {
                found = 1;
                break;
            } else if (arr[mid] < nums2[i]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (found) {
            int duplicate = 0;

            for (int k = 0; k < j; k++) {
                if (result[k] == nums2[i]) {
                    duplicate = 1;
                    break;
                }
            }

            if (!duplicate) {
                result[j++] = nums2[i];
            }
        }
    }

    free(arr);
    *returnSize = j;

    return result;
}