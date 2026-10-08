#include <math.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {

    for (int i = 0; i < 31; i++) {

        int ans = (int)pow(2, i);

        if (ans == n) {
            return true;
        }
    }

    return false;
}