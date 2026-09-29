#include <stdbool.h>

bool validateStackSequences(int* pushed, int pushedSize,
                            int* popped, int poppedSize) {

    if (pushedSize != poppedSize) {
        return false;
    }

    int stack[pushedSize];
    int top = -1;

    int j = 0;

    for (int i = 0; i < pushedSize; i++) {

        // Push
        stack[++top] = pushed[i];

        // Pop whenever top matches popped[j]
        while (top != -1 && stack[top] == popped[j]) {
            top--;
            j++;
        }
    }

    return top == -1;
}