char findTheDifference(char* s, char* t) {
    char c = 0;

    // XOR all characters in s
    for (int i = 0; s[i] != '\0'; i++) {
        c ^= s[i];
    }

    // XOR all characters in t
    for (int i = 0; t[i] != '\0'; i++) {
        c ^= t[i];
    }

    return c;
}