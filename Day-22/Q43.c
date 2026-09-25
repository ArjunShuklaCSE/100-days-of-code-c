/*
Q43: Write a program to check if a number is a strong number.

Sample Test Cases:
Input 1:
145
Output 1:
Strong number

Input 2:
123
Output 2:
Not strong number
*/

#include <stdio.h>

int main() {
    int n, temp, sum = 0;
    scanf("%d", &n);
    temp = n;
    while (temp > 0) {
        int d = temp % 10, fact = 1;
        for (int i = 2; i <= d; i++) {
            fact *= i;
        }
        sum += fact;
        temp /= 10;
    }
    if (n > 0 && sum == n) {
        printf("Strong number\n");
    } else {
        printf("Not strong number\n");
    }
    return 0;
}
