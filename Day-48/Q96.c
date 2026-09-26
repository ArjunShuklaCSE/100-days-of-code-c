/*
Q96: Reverse each word in a sentence without changing the word order.

Sample Test Cases:
Input 1:
I love coding
Output 1:
I evol gnidoc
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int i = 0;
    while (str[i] != '\0') {
        while (str[i] == ' ') i++;
        int start = i;
        while (str[i] != ' ' && str[i] != '\0') i++;
        for (int a = start, b = i - 1; a < b; a++, b--) {
            char temp = str[a];
            str[a] = str[b];
            str[b] = temp;
        }
    }
    printf("%s\n", str);
    return 0;
}
