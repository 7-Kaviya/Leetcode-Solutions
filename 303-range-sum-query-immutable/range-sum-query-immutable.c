typedef struct {
    int* prefixSum;
    int size;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = malloc(sizeof(NumArray));

    obj->prefixSum = malloc(numsSize * sizeof(int));
    obj->size = numsSize;

    if (numsSize > 0) {
        obj->prefixSum[0] = nums[0];

        for (int i = 1; i < numsSize; i++) {
            obj->prefixSum[i] = nums[i] + obj->prefixSum[i - 1];
        }
    }

    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    if (left == 0) {
        return obj->prefixSum[right];
    }

    return obj->prefixSum[right] - obj->prefixSum[left - 1];
}

void numArrayFree(NumArray* obj) {
    free(obj->prefixSum);
    free(obj);
}