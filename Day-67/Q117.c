/*
Q117: Write a program to take two sorted arrays of size m and n as input. Merge both the arrays such that the merged array is also sorted. Print the merged array.

Sample Test Cases:
Input 1:
nums1 = [2,7,11,15] nums2 = [4,8,10]
Output 1:
2 4 7 8 10 11 15

Input 2:
nums1 = [1,2,7] nums2 = [9,10,17]
Output 2:
1 2 7 9 10 17

Input 3:
nums1 = [-10,-2,7] nums2 = [-3, -1, 7]
Output 3:
-10 -3 -2 -1 7 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// reads the numbers inside the next [ ... ] after *p and moves *p past the ]
// (only inside the brackets, so the 1 and 2 in "nums1" and "nums2" are skipped)
int readList(char **p, int out[], int max) {
    int n = 0;
    char *s = strchr(*p, '[');
    if (s == NULL) return 0;
    s++;
    while (*s != '\0' && *s != ']' && n < max) {
        if (isdigit((unsigned char)*s) || (*s == '-' && isdigit((unsigned char)s[1]))) {
            out[n++] = (int)strtol(s, &s, 10);
        } else {
            s++;
        }
    }
    *p = s;
    return n;
}

int main() {
    char line[4000];
    int a[500], b[500];
    fgets(line, sizeof(line), stdin);

    // input looks like: nums1 = [2,7,11,15] nums2 = [4,8,10]
    char *p = line;
    int m = readList(&p, a, 500);
    int n = readList(&p, b, 500);

    // two pointers: always take the smaller front element, then whatever is left over: O(m + n)
    int i = 0, j = 0, printed = 0;
    while (i < m || j < n) {
        int next;
        if (j >= n || (i < m && a[i] <= b[j])) {
            next = a[i++];
        } else {
            next = b[j++];
        }
        printf(printed++ == 0 ? "%d" : " %d", next);
    }
    printf("\n");
    return 0;
}
