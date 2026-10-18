/*
Q120: Write a program to take a string input. Change it to sentence case.

Sample Test Cases:
Input 1:
str = I am trying to build logic.
Output 1:
I Am Trying To Build Logic

Input 2:
str = The classes are supposed to start early.
Output 2:
The Classes Are Supposed To Start Early.

Input 3:
str = We are going to look at 26 different test cases.
Output 3:
We Are Going To Look At 26 Different Test Cases.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char line[2000];
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';
    line[strcspn(line, "\r\n")] = '\0';

    // input looks like: str = I am trying to build logic.  -> the text is everything after "str ="
    char *s = line;
    char *eq = strchr(line, '=');
    if (strncmp(line, "str", 3) == 0 && eq != NULL) {
        s = eq + 1;
        while (*s == ' ') s++;
    }

    // the samples capitalise the first letter of every word, so do that and leave the rest as typed
    for (int i = 0; s[i] != '\0'; i++) {
        if (i == 0 || isspace((unsigned char)s[i - 1])) {
            s[i] = (char)toupper((unsigned char)s[i]);
        }
    }
    printf("%s\n", s);
    return 0;
}
