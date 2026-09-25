/*
Q29: Write a program to calculate the factorial of a number.

Sample Test Cases:
Input 1:
5
Output 1:
120

Input 2:
3
Output 2:
6
*/

#include <stdio.h>

int main() {
    int n;
    long long fact = 1;
    scanf("%d", &n);
    if (n < 0) {
        printf("Factorial of a negative number doesn't exist\n");
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    printf("%lld\n", fact);
    return 0;
}
