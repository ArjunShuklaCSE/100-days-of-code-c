/*
Q118: Write a program to take an input array of size n. The array should contain all the integers between 0 to n except for one. Print that missing number

Sample Test Cases:
Input 1:
nums1 = [0,3,2,4]
Output 1:
1

Input 2:
nums1 = [1,2,3]
Output 2:
0

Input 3:
nums1 = [0,4,3,1,5]
Output 3:
2
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char line[2000];
    long long sum = 0;
    int n = 0;
    fgets(line, sizeof(line), stdin);

    // input looks like: nums1 = [0,3,2,4]  -> read the numbers inside the brackets only
    // (so the 1 in "nums1" is not counted)
    char *p = strchr(line, '[');
    p = (p != NULL) ? p + 1 : line;
    while (*p != '\0' && *p != ']') {
        if (isdigit((unsigned char)*p) || (*p == '-' && isdigit((unsigned char)p[1]))) {
            sum += strtoll(p, &p, 10);
            n++;
        } else {
            p++;
        }
    }

    // 0 + 1 + ... + n = n * (n + 1) / 2, and the missing number is whatever the array falls short by: O(n)
    long long expected = (long long)n * (n + 1) / 2;
    printf("%lld\n", expected - sum);
    return 0;
}
