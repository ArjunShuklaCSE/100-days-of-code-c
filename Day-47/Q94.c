/*
Q94: Find the longest word in a sentence.

Sample Test Cases:
Input 1:
I love programming
Output 1:
programming
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int bestStart = 0, bestLen = 0, i = 0;
    while (str[i] != '\0') {
        while (str[i] == ' ') i++;
        int start = i;
        while (str[i] != ' ' && str[i] != '\0') i++;
        if (i - start > bestLen) {
            bestLen = i - start;
            bestStart = start;
        }
    }
    for (int j = bestStart; j < bestStart + bestLen; j++) {
        printf("%c", str[j]);
    }
    printf("\n");
    return 0;
}
