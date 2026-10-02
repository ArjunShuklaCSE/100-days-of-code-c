/*
Q104: Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.

Sample Test Cases:
Input 1:
n = 8
Output 1:
6

Input 2:
n = 1
Output 2:
1

Input 3:
n = 4
Output 3:
-1
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main() {
    char line[100];
    long long n = 0;
    fgets(line, sizeof(line), stdin);

    // input looks like: n = 8  -> pick out the number
    char *p = line;
    while (*p != '\0' && !isdigit((unsigned char)*p)) p++;
    n = strtoll(p, NULL, 10);
    if (n < 1) {
        printf("-1\n");
        return 0;
    }

    // 1 + ... + x = x + ... + n  works out to  x * x = n * (n + 1) / 2
    // so x is the square root of the total sum, if the total is a perfect square: O(1)
    long long total = n * (n + 1) / 2;
    long long x = (long long)sqrt((double)total);
    while (x * x > total) x--;               // fix any floating point rounding
    while ((x + 1) * (x + 1) <= total) x++;

    if (x * x == total) {
        printf("%lld\n", x);
    } else {
        printf("-1\n");
    }
    return 0;
}
