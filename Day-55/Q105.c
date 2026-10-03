/*
Q105: Write a program to take an integer array nums of size n, and print the majority element. The majority element is the element that appears strictly more than ⌊n / 2⌋ times. Print -1 if no such element exists. Note: Majority Element is not necessarily the element that is present most number of times.

Sample Test Cases:
Input 1:
nums = [3,2,3]
Output 1:
3

Input 2:
nums = [2,2,1,1,1,2,2]
Output 2:
2

Input 3:
nums = [2,2,1,1,1,2,2,3]
Output 3:
-1
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char line[2000];
    int nums[500], n = 0;
    fgets(line, sizeof(line), stdin);

    // input looks like: nums = [3,2,3]  -> pick out every number
    char *p = line;
    while (*p != '\0' && n < 500) {
        if (isdigit((unsigned char)*p) || (*p == '-' && isdigit((unsigned char)p[1]))) {
            nums[n++] = (int)strtol(p, &p, 10);
        } else {
            p++;
        }
    }

    // Boyer-Moore voting: a majority element survives every cancellation of unequal pairs: O(n)
    int candidate = 0, votes = 0;
    for (int i = 0; i < n; i++) {
        if (votes == 0) candidate = nums[i];
        votes += (nums[i] == candidate) ? 1 : -1;
    }

    // the survivor is only a candidate, so count it to make sure it really is the majority
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate) count++;
    }

    if (n > 0 && count > n / 2) {
        printf("%d\n", candidate);
    } else {
        printf("-1\n");
    }
    return 0;
}
