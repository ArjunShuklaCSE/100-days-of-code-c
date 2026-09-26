/*
Q95: Check if one string is a rotation of another.

Sample Test Cases:
Input 1:
abcde
deabc
Output 1:
Rotation

Input 2:
abc
acb
Output 2:
Not rotation
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s1[1000], s2[1000], doubled[2000];
    fgets(s1, sizeof(s1), stdin);
    fgets(s2, sizeof(s2), stdin);
    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';

    // s2 is a rotation of s1 if it has the same length and appears inside s1 + s1
    strcpy(doubled, s1);
    strcat(doubled, s1);
    if (strlen(s1) == strlen(s2) && strstr(doubled, s2) != NULL) {
        printf("Rotation\n");
    } else {
        printf("Not rotation\n");
    }
    return 0;
}
