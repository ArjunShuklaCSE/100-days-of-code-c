/*
Q115: Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".

Sample Test Cases:
Input 1:
s = "anagram", t = "nagaram"
Output 1:
Anagram

Input 2:
s = "rat", t = "car"
Output 2:
Not Anagram
*/

#include <stdio.h>
#include <string.h>

int main() {
    char line[2000], s[1000] = "", t[1000] = "";
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';

    // input looks like: s = "anagram", t = "nagaram"  -> the two strings are the two quoted parts
    // (a line with no quotes is read as two words: anagram nagaram)
    char *q1 = strchr(line, '"');
    char *q2 = q1 ? strchr(q1 + 1, '"') : NULL;
    char *q3 = q2 ? strchr(q2 + 1, '"') : NULL;
    char *q4 = q3 ? strchr(q3 + 1, '"') : NULL;
    if (q4 != NULL) {
        *q2 = '\0';
        *q4 = '\0';
        strcpy(s, q1 + 1);
        strcpy(t, q3 + 1);
    } else {
        sscanf(line, "%999s %999s", s, t);
    }

    // count each character up for s and down for t; anagrams cancel out to all zeros: O(n)
    int count[256] = {0};
    for (int i = 0; s[i] != '\0'; i++) count[(unsigned char)s[i]]++;
    for (int i = 0; t[i] != '\0'; i++) count[(unsigned char)t[i]]--;

    for (int c = 0; c < 256; c++) {
        if (count[c] != 0) {
            printf("Not Anagram\n");
            return 0;
        }
    }
    printf("Anagram\n");
    return 0;
}
