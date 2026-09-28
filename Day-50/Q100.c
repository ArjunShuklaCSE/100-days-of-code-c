/*
Q100: Print all sub-strings of a string.

Sample Test Cases:
Input 1:
abc
Output 1:
a,ab,abc,b,bc,c
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int len = strlen(str), first = 1;
    for (int start = 0; start < len; start++) {
        for (int end = start; end < len; end++) {
            if (!first) printf(",");
            for (int k = start; k <= end; k++) {
                printf("%c", str[k]);
            }
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
