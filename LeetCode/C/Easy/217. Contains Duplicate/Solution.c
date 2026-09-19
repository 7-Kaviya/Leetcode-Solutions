bool containsDuplicate(int* nums, int numsSize) {
    char *m = calloc(1, 2 * (size_t)1e9 + 10), *a = m + (size_t)1e9 + 5;
    for (; numsSize-- && !a[*nums] ; a[*nums++] = 1);
    return free(m), numsSize + 1;
}