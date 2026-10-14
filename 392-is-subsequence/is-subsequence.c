#include <stdbool.h>
#include <string.h>

bool check(char* s, char* t, int i, int j) {
    if (i == strlen(s)) {
        return true;
    }

    if (j == strlen(t)) {
        return false;
    }

    if (s[i] == t[j]) {
        return check(s, t, i + 1, j + 1);
    }

    return check(s, t, i, j + 1);
}

bool isSubsequence(char* s, char* t) {
    return check(s, t, 0, 0);
}