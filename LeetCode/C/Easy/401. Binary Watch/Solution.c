#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void is_valid(int minute, int hour, char** res, int* count) {
    if (hour <= 11 && minute <= 59) {
        res[*count] = (char*)malloc(6 * sizeof(char));

        sprintf(res[*count], "%d:%02d", hour, minute);
        (*count)++;
    }
}

/**
 * Note: The returned array must be malloced.
 * The strings and the array are allocated dynamically.
 */
char** readBinaryWatch(int k, int* returnSize) {
    *returnSize = 0;

    if (k == 0) {
        char** res = (char**)malloc(sizeof(char*));
        res[0] = (char*)malloc(5 * sizeof(char));
        strcpy(res[0], "0:00");
        *returnSize = 1;
        return res;
    }

    if (k >= 9) {
        return NULL;
    }

    char** res = (char**)malloc(1024 * sizeof(char*));
    int count = 0;

    int mask = (1 << 6) - 1;
    int q = (1 << k) - 1;
    int limit = q << (10 - k);

    while (q <= limit) {
        int minute = q & mask;
        int hour = q >> 6;

        is_valid(minute, hour, res, &count);

        int r = q & -q;
        int n = q + r;

        q = (((q ^ n) / r) >> 2) | n;
    }

    *returnSize = count;
    return res;
}