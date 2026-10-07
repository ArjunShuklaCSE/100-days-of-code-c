/*
Q108: Write a Program to take an integer array nums. Print an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Sample Test Cases:
Input 1:
nums = [1,2,3,4]
Output 1:
[24,12,8,6]

Input 2:
nums = [-1,1,0,-3,3]
Output 2:
[0,0,9,0,0]
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char line[2000];
    int nums[500], answer[500], n = 0;
    fgets(line, sizeof(line), stdin);

    // input looks like: nums = [1,2,3,4]  -> pick out every number
    char *p = line;
    while (*p != '\0' && n < 500) {
        if (isdigit((unsigned char)*p) || (*p == '-' && isdigit((unsigned char)p[1]))) {
            nums[n++] = (int)strtol(p, &p, 10);
        } else {
            p++;
        }
    }

    // no division (so zeros are fine): answer[i] = product of everything left of i * everything right of i: O(n)
    int left = 1;
    for (int i = 0; i < n; i++) {
        answer[i] = left;
        left *= nums[i];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= right;
        right *= nums[i];
    }

    printf("[");
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%d" : ",%d", answer[i]);
    }
    printf("]\n");
    return 0;
}
