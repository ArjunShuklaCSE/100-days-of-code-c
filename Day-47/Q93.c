/*
Q93: Check if two strings are anagrams of each other.

Sample Test Cases:
Input 1:
listen
silent
Output 1:
Anagrams

Input 2:
hello
world
Output 2:
Not anagrams
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s1[1000], s2[1000];
    int count[256] = {0};
    fgets(s1, sizeof(s1), stdin);
    fgets(s2, sizeof(s2), stdin);
    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';
    for (int i = 0; s1[i] != '\0'; i++) count[(unsigned char)s1[i]]++;
    for (int i = 0; s2[i] != '\0'; i++) count[(unsigned char)s2[i]]--;
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            printf("Not anagrams\n");
            return 0;
        }
    }
    printf("Anagrams\n");
    return 0;
}
