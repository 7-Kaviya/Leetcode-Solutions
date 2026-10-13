/**
 * Forward declaration of guess API.
 * @param num your guess
 * @return -1 if num is higher than the picked number
 *          1 if num is lower than the picked number
 *          0 if the guess is correct
 */
int guess(int num);

int guessNumber(int n) {
    int left = 1;
    int right = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int result = guess(mid);

        if (result == 0) {
            return mid;
        } else if (result == 1) {
            // Our guess is too low
            left = mid + 1;
        } else {
            // Our guess is too high
            right = mid - 1;
        }
    }

    return -1;
}