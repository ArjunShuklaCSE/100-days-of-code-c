/*
Q102: Write a Program to take a sorted array arr[] and an integer x as input, find the index (0-based) of the smallest element in arr[] that is greater than or equal to x and print it. This element is called the ceil of x. If such an element does not exist, print -1. Note: In case of multiple occurrences of ceil of x, return the index of the first occurrence.

Sample Test Cases:
Input 1:
arr = [1, 2, 8, 10, 11, 12, 19], x = 5
Output 1:
2

Input 2:
arr = [1, 2, 8, 10, 11, 12, 19], x = 20
Output 2:
-1

Input 3:
arr = [1, 1, 2, 8, 10, 11, 12, 19], x = 0
Output 3:
0

Input 4:
arr = [1, 1, 2, 8, 10, 11, 12, 19], x = 2
Output 4:
2
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char line[2000];
    int values[501], count = 0;
    fgets(line, sizeof(line), stdin);

    // input looks like: arr = [1, 2, 8, 10, 11, 12, 19], x = 5
    // pick out every number; the last one is x, the rest are the array
    char *p = line;
    while (*p != '\0' && count < 501) {
        if (isdigit((unsigned char)*p) || (*p == '-' && isdigit((unsigned char)p[1]))) {
            values[count++] = (int)strtol(p, &p, 10);
        } else {
            p++;
        }
    }
    if (count < 1) {
        printf("Invalid input\n");
        return 0;
    }

    int x = values[count - 1];
    int n = count - 1;

    // binary search for the first element >= x
    int low = 0, high = n - 1, ceilIndex = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (values[mid] >= x) {
            ceilIndex = mid;
            high = mid - 1;   // look for an earlier one on the left
        } else {
            low = mid + 1;
        }
    }
    printf("%d\n", ceilIndex);
    return 0;
}
