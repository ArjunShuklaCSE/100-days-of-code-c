/*
Q54: Write a program to print the following pattern:

   *
  ***
 *****
*******
 *****
  ***
   *


Sample Test Cases:
Input 1:

Output 1:
Pattern with layers of stars as shown.
*/

#include <stdio.h>

int main() {
    int n = 4;
    for (int i = 1; i <= 2 * n - 1; i++) {
        int row;
        if (i <= n) row = i;
        else row = 2 * n - i;
        for (int j = 1; j <= n - row; j++) {
            printf(" ");
        }
        for (int j = 1; j <= 2 * row - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
