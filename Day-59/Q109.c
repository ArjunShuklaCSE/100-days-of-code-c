/*
Q109: Write a program to take an integer array arr and an integer k as inputs. Print the maximum sum of all the subarrays of size k.

Sample Test Cases:
Input 1:
arr[100, 200, 300, 400] = , k = 2
Output 1:
700

Input 2:
arr[1, 4, 2, 10, 23, 3, 1, 0, 20] = , k = 4
Output 2:
39

Input 3:
arr[100, 200, 300, 400] = , k = 1
Output 3:
400
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char line[2000];
    long long nums[501];
    int count = 0;
    fgets(line, sizeof(line), stdin);

    // input looks like: arr[100, 200, 300, 400] = , k = 2  -> pick out every number, the last one is k
    char *p = line;
    while (*p != '\0' && count < 501) {
        if (isdigit((unsigned char)*p) || (*p == '-' && isdigit((unsigned char)p[1]))) {
            nums[count++] = strtoll(p, &p, 10);
        } else {
            p++;
        }
    }
    int n = count - 1;
    int k = count > 0 ? (int)nums[count - 1] : 0;
    if (k < 1 || k > n) {
        printf("Invalid k\n");
        return 0;
    }

    // sliding window: add the element coming in, drop the one going out: O(n)
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    long long best = sum;
    for (int i = k; i < n; i++) {
        sum += nums[i] - nums[i - k];
        if (sum > best) best = sum;
    }
    printf("%lld\n", best);
    return 0;
}
