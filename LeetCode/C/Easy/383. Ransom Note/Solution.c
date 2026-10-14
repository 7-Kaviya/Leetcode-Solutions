#include <stdbool.h>
#include <string.h>

bool canConstruct(char* ransomNote, char* magazine) {
    if (strlen(ransomNote) > strlen(magazine)) {
        return false;
    }

    int alphabets_counter[26] = {0};

    // Count each character in magazine
    for (int i = 0; magazine[i] != '\0'; i++) {
        alphabets_counter[magazine[i] - 'a']++;
    }

    // Check whether ransomNote can be constructed
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        int index = ransomNote[i] - 'a';

        if (alphabets_counter[index] == 0) {
            return false;
        }

        alphabets_counter[index]--;
    }

    return true;
}