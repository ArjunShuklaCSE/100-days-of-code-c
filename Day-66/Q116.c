/*
Q116: Write a program to take an integer array nums which contains only positive integers, and an integer target as inputs. The goal is to find two distinct indices i and j in the array such that nums[i] + nums[j] equals the target. Assume exactly one solution exists and return the indices in any order. Print the two indices separated by a space as output. If no solution exists, print "-1 -1".

Sample Test Cases:
Input 1:
nums = [2,7,11,15], target = 9
Output 1:
0 1

Input 2:
nums = [3,2,4], target = 6
Output 2:
1 2

Input 3:
nums = [3,3], target = 6
Output 3:
0 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char line[2000];
    long long nums[501];
    int count = 0;
    fgets(line, sizeof(line), stdin);

    // input looks like: nums = [2,7,11,15], target = 9  -> pick out every number, the last one is the target
    char *p = line;
    while (*p != '\0' && count < 501) {
        if (isdigit((unsigned char)*p) || (*p == '-' && isdigit((unsigned char)p[1]))) {
            nums[count++] = strtoll(p, &p, 10);
        } else {
            p++;
        }
    }
    int n = count - 1;
    long long target = count > 0 ? nums[count - 1] : 0;

    // try every pair i < j: O(n^2), plenty fast for an array typed on one line
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("-1 -1\n");
    return 0;
}
