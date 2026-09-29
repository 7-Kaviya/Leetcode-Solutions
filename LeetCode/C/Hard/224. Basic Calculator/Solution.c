#include <string.h>
#include <ctype.h>

int calculate(char* s) {

    int n = strlen(s);

    long long stack[n * 2];
    int top = -1;

    long long res = 0;
    long long curr = 0;
    long long sign = 1;

    for (int i = 0; i < n; i++) {

        char c = s[i];

        if (isdigit(c)) {
            curr = curr * 10 + (c - '0');
        }

        else if (c == '+') {
            res += curr * sign;
            sign = 1;
            curr = 0;
        }

        else if (c == '-') {
            res += curr * sign;
            sign = -1;
            curr = 0;
        }

        else if (c == '(') {
            stack[++top] = res;
            stack[++top] = sign;

            res = 0;
            sign = 1;
            curr = 0;
        }

        else if (c == ')') {
            res += curr * sign;
            curr = 0;

            long long previous_sign = stack[top--];
            long long previous_res = stack[top--];

            res *= previous_sign;
            res += previous_res;
        }
    }

    res += sign * curr;

    return (int)res;
}