/*
Q110: Write a program to take an integer array arr and an integer k as inputs. The task is to find the maximum element in each subarray of size k moving from left to right. Print the maximum elements for each window separated by spaces as output.

Sample Test Cases:
Input 1:
arr[1, 2, 3, 1, 4, 5, 2, 3, 6] = , k = 3
Output 1:
3 3 4 5 5 5 6

Input 2:
arr[5, 1, 3, 4, 2] = , k = 1
Output 2:
5 1 3 4 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char line[2000];
    int nums[501], count = 0;
    fgets(line, sizeof(line), stdin);

    // input looks like: arr[1, 2, 3] = , k = 3  -> pick out every number, the last one is k
    char *p = line;
    while (*p != '\0' && count < 501) {
        if (isdigit((unsigned char)*p) || (*p == '-' && isdigit((unsigned char)p[1]))) {
            nums[count++] = (int)strtol(p, &p, 10);
        } else {
            p++;
        }
    }
    int n = count - 1;
    int k = count > 0 ? nums[count - 1] : 0;
    if (k < 1 || k > n) {
        printf("Invalid k\n");
        return 0;
    }

    // check every window of size k and print its biggest element: O(n * k)
    for (int i = 0; i + k <= n; i++) {
        int max = nums[i];
        for (int j = i + 1; j < i + k; j++) {
            if (nums[j] > max) max = nums[j];
        }
        printf(i == 0 ? "%d" : " %d", max);
    }
    printf("\n");
    return 0;
}
