/*
Q119: Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.

Sample Test Cases:
Input 1:
nums1 = [1,3,3,4]
Output 1:
3

Input 2:
nums1 = [1,2,2]
Output 2:
2

Input 3:
nums1 = [0,4,1,1,5]
Output 3:
1
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SLOTS 1024   // more than twice the 500 numbers we read, so the table never fills up

int main() {
    char line[2000];
    int table[SLOTS];
    char used[SLOTS] = {0};
    int n = 0;
    fgets(line, sizeof(line), stdin);

    // input looks like: nums1 = [1,3,3,4]  -> read the numbers inside the brackets only
    // (so the 1 in "nums1" is not counted)
    char *p = strchr(line, '[');
    p = (p != NULL) ? p + 1 : line;

    // one single iteration: keep every number seen so far in a small hash table,
    // and the first number that is already in it is the repeated one: O(n)
    while (*p != '\0' && *p != ']' && n < 500) {
        if (isdigit((unsigned char)*p) || (*p == '-' && isdigit((unsigned char)p[1]))) {
            int x = (int)strtol(p, &p, 10);
            n++;
            unsigned slot = (unsigned)x % SLOTS;
            while (used[slot] && table[slot] != x) slot = (slot + 1) % SLOTS;   // linear probing
            if (used[slot]) {
                printf("%d\n", x);
                return 0;
            }
            used[slot] = 1;
            table[slot] = x;
        } else {
            p++;
        }
    }
    printf("No repeated element\n");
    return 0;
}
