/*
Q53: Write a program to print the following pattern:
*
***
*****
*******
*********
*******
*****
***
*

Sample Test Cases:
Input 1:

Output 1:
*
***
*****
*******
*********
*******
*****
***
*
*/

#include <stdio.h>

int main() {
    for (int i = 1; i <= 9; i++) {
        int stars;
        if (i <= 5) stars = 2 * i - 1;
        else stars = 2 * (10 - i) - 1;
        for (int j = 1; j <= stars; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
