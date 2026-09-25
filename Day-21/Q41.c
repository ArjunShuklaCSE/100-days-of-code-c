/*
Q41: Write a program to swap the first and last digit of a number.

Sample Test Cases:
Input 1:
1234
Output 1:
4231

Input 2:
1001
Output 2:
1001
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n < 10) {
        printf("%d\n", n);
        return 0;
    }
    int last = n % 10;
    int div = 1;
    while (n / div >= 10) {
        div *= 10;
    }
    int first = n / div;
    int middle = (n % div) / 10;
    printf("%d\n", last * div + middle * 10 + first);
    return 0;
}
