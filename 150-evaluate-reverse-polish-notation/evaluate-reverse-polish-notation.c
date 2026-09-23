#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {

        if (strcmp(tokens[i], "+") == 0) {
            int second = stack[top--];
            int first = stack[top--];
            stack[++top] = first + second;
        }

        else if (strcmp(tokens[i], "-") == 0) {
            int second = stack[top--];
            int first = stack[top--];
            stack[++top] = first - second;
        }

        else if (strcmp(tokens[i], "*") == 0) {
            int second = stack[top--];
            int first = stack[top--];
            stack[++top] = first * second;
        }

        else if (strcmp(tokens[i], "/") == 0) {
            int second = stack[top--];
            int first = stack[top--];
            stack[++top] = first / second;
        }

        else {
            stack[++top] = atoi(tokens[i]);
        }
    }

    return stack[top];
}