/*
Q112: Write a program to take an integer array arr as input. The task is to find the maximum sum of any contiguous subarray using Kadane's algorithm. Print the maximum sum as output. If all elements are negative, print the largest (least negative) element.

Sample Test Cases:
Input 1:
arr[] = [2, 3, -8, 7, -1, 2, 3]
Output 1:
11

Input 2:
arr[] = [-2, -4]
Output 2:
-2

Input 3:
arr[] = [5, 4, 1, 7, 8]
Output 3:
25
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char line[2000];
    long long nums[500];
    int n = 0;
    fgets(line, sizeof(line), stdin);

    // input looks like: arr[] = [2, 3, -8, 7]  -> pick out every number
    char *p = line;
    while (*p != '\0' && n < 500) {
        if (isdigit((unsigned char)*p) || (*p == '-' && isdigit((unsigned char)p[1]))) {
            nums[n++] = strtoll(p, &p, 10);
        } else {
            p++;
        }
    }
    if (n == 0) {
        printf("Empty array\n");
        return 0;
    }

    // Kadane: at each element, either extend the best run ending just before it or start fresh here: O(n)
    // starting from nums[0] (not 0) means an all-negative array gives its largest element
    long long current = nums[0], best = nums[0];
    for (int i = 1; i < n; i++) {
        current = (current + nums[i] > nums[i]) ? current + nums[i] : nums[i];
        if (current > best) best = current;
    }
    printf("%lld\n", best);
    return 0;
}
