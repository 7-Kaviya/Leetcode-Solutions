#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool wordPattern(char* pattern, char* s) {
    char* words[10000];
    int wordCount = 0;

    // Split s into words using spaces
    char* token = strtok(s, " ");

    while (token != NULL) {
        words[wordCount++] = token;
        token = strtok(NULL, " ");
    }

    int n = strlen(pattern);

    if (n != wordCount) {
        return false;
    }

    char* charToWord[256] = {NULL};
    char* wordToChar[10000] = {NULL};

    for (int i = 0; i < n; i++) {
        unsigned char c = pattern[i];
        char* w = words[i];

        // Check character-to-word mapping
        if (charToWord[c] != NULL) {
            if (strcmp(charToWord[c], w) != 0) {
                return false;
            }
        } else {
            charToWord[c] = w;
        }

        // Check word-to-character mapping
        if (wordToChar[i] != NULL) {
            // Not used; reverse mapping is checked below.
        }

        for (int j = 0; j < i; j++) {
            if (strcmp(words[j], w) == 0 && pattern[j] != c) {
                return false;
            }
        }
    }

    return true;
}