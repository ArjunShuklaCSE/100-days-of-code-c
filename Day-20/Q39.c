/*
Q39: Write a program to find the product of odd digits of a number.

Sample Test Cases:
Input 1:
12345
Output 1:
15 (1*3*5)

Input 2:
2468
Output 2:
1 (no odd digits, assume 1)
*/

#include <stdio.h>

int main() {
    int n, product = 1, found = 0;
    scanf("%d", &n);
    if (n < 0) n = -n;

    int temp = n;
    while (temp > 0) {
        int d = temp % 10;
        if (d % 2 == 1) {
            product *= d;
            found = 1;
        }
        temp /= 10;
    }

    if (!found) {
        printf("1 (no odd digits, assume 1)\n");
        return 0;
    }

    // print the odd digits from left to right
    int div = 1;
    while (n / div >= 10) {
        div *= 10;
    }
    printf("%d (", product);
    int first = 1;
    while (div > 0) {
        int d = (n / div) % 10;
        if (d % 2 == 1) {
            if (!first) printf("*");
            printf("%d", d);
            first = 0;
        }
        div /= 10;
    }
    printf(")\n");
    return 0;
}
