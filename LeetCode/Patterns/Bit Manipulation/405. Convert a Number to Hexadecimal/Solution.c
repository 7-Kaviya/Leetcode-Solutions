#include <stdlib.h>

char* toHex(int num) {
    char map[] = "0123456789abcdef";

    if (num == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    char* result = (char*)malloc(9 * sizeof(char));
    int i = 8;
    result[i] = '\0';

    unsigned int n = (unsigned int)num;

    while (n != 0) {
        result[--i] = map[n & 15];
        n >>= 4;
    }

    // Move the result to the beginning of the allocated string
    int j = 0;
    while (result[i] != '\0') {
        result[j++] = result[i++];
    }
    result[j] = '\0';

    return result;
}