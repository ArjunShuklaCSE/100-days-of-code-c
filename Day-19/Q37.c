/*
Q37: Write a program to find the LCM of two numbers.

Sample Test Cases:
Input 1:
4 5
Output 1:
20

Input 2:
7 3
Output 2:
21
*/

#include <stdio.h>

int main() {
    int a, b, x, y;
    scanf("%d %d", &a, &b);
    x = a;
    y = b;
    while (y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    printf("%d\n", a / x * b);
    return 0;
}
