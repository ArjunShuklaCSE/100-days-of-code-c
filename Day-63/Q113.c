/*
Q113: Write a program to take an integer array arr and an integer k as inputs. The task is to find the kth smallest element in the array. Print the kth smallest element as output.

Sample Test Cases:
Input 1:
arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
Output 1:
5

Input 2:
arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output 2:
7
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int compare(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);   // not x - y, which can overflow
}

int main() {
    char line[2000];
    int nums[501], count = 0;
    fgets(line, sizeof(line), stdin);

    // input looks like: arr[] = [7, 10, 4], k = 3  -> pick out every number, the last one is k
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

    // sort the array, then the kth smallest sits at index k - 1: O(n log n)
    qsort(nums, n, sizeof(int), compare);
    printf("%d\n", nums[k - 1]);
    return 0;
}
