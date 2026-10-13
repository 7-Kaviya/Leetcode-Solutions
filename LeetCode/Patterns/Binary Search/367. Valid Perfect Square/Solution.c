#include <stdbool.h>

bool isPerfectSquare(int num) {
    int left = 1, right = num;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Use long long to prevent integer overflow
        long long midSquare = (long long)mid * mid;

        if (midSquare == num) {
            return true;
        } else if (midSquare > num) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return false;
}