/*
Q88: Replace spaces with hyphens in a string.

Sample Test Cases:
Input 1:
hello world
Output 1:
hello-world
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') str[i] = '-';
    }
    printf("%s\n", str);
    return 0;
}
