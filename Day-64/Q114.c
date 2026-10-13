/*
Q114: Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.

Sample Test Cases:
Input 1:
s = "abcabcbb"
Output 1:
3

Input 2:
s = "bbbbb"
Output 2:
1

Input 3:
s = "pwwkew"
Output 3:
3
*/

#include <stdio.h>
#include <string.h>

int main() {
    char line[2000];
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';
    line[strcspn(line, "\r\n")] = '\0';

    // input looks like: s = "abcabcbb"  -> the string is what sits between the first and last quote
    // (a line with no quotes is taken as the string itself)
    char *s = line;
    char *open = strchr(line, '"');
    char *close = strrchr(line, '"');
    if (open != NULL && close > open) {
        s = open + 1;
        *close = '\0';
    }

    // sliding window: remember where each character was last seen, and when one repeats
    // inside the window, move the window's start to just past its earlier position: O(n)
    int lastSeen[256];
    for (int i = 0; i < 256; i++) lastSeen[i] = -1;

    int start = 0, best = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char c = (unsigned char)s[i];
        if (lastSeen[c] >= start) start = lastSeen[c] + 1;
        lastSeen[c] = i;
        if (i - start + 1 > best) best = i - start + 1;
    }
    printf("%d\n", best);
    return 0;
}
