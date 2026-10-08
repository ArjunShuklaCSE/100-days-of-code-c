/*
Q111: Write a program to take an integer array arr and an integer k as inputs. The task is to find the first negative integer in each subarray of size k moving from left to right. If no negative exists in a window, print "0" for that window. Print the results separated by spaces as output.

Sample Test Cases:
Input 1:
arr[] = [-8, 2, 3, -6, 10], k = 2
Output 1:
-8 0 -6 -6

Input 2:
arr[] = [12, -1, -7, 8, -15, 30, 16, 28], k = 3
Output 2:
-1 -1 -7 -15 -15 0

Input 3:
arr[] = [12, 1, 3, 5], k = 3
Output 3:
0 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char line[2000];
    int nums[501], count = 0;
    fgets(line, sizeof(line), stdin);

    // input looks like: arr[] = [-8, 2, 3], k = 2  -> pick out every number, the last one is k
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

    // keep the index of the first negative at or after the window start, so each window is O(1): O(n) overall
    int neg = 0;
    for (int i = 0; i + k <= n; i++) {
        if (neg < i) neg = i;
        while (neg < i + k && nums[neg] >= 0) neg++;
        printf(i == 0 ? "%d" : " %d", neg < i + k ? nums[neg] : 0);
    }
    printf("\n");
    return 0;
}
