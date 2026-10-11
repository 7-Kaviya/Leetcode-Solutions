/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    *returnSize = n + 1;

    int sub = 1;
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (sub * 2 == i) {
            sub = i;
        }

        dp[i] = dp[i - sub] + 1;
    }

    return dp;
}