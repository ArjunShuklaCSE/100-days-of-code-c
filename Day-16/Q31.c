/*
Q31: Write a program to take a number as input and print its equivalent binary representation.

Sample Test Cases:
Input 1:
10
Output 1:
1010

Input 2:
7
Output 2:
111
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    int power = 1;
    while (power <= n / 2) {
        power *= 2;
    }
    while (power > 0) {
        printf("%d", (n / power) % 2);
        power /= 2;
    }
    printf("\n");
    return 0;
}
