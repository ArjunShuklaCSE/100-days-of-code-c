/*
Q92: Find the first repeating lowercase alphabet in a string.

Sample Test Cases:
Input 1:
stress
Output 1:
s
*/

#include <stdio.h>

int main() {
    char str[1000];
    int seen[26] = {0};
    fgets(str, sizeof(str), stdin);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            if (seen[str[i] - 'a']) {
                printf("%c\n", str[i]);
                return 0;
            }
            seen[str[i] - 'a'] = 1;
        }
    }
    printf("No repeating lowercase alphabet\n");
    return 0;
}
