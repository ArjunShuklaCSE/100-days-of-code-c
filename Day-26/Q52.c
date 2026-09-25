/*
Q52: Write a program to print the following pattern:

*

*
*
*

*
*
*
*
*

*
*
*

*



Sample Test Cases:
Input 1:

Output 1:
Pattern with stars spaced irregularly as shown.
*/

#include <stdio.h>

int main() {
    // groups of 1, 3, 5, 3, 1 stars, one star per line, separated by blank lines
    for (int i = 1; i <= 5; i++) {
        int stars;
        if (i <= 3) stars = 2 * i - 1;
        else stars = 2 * (6 - i) - 1;
        printf("\n");
        for (int j = 1; j <= stars; j++) {
            printf("*\n");
        }
    }
    return 0;
}
