/*
Q101: Write a Program to take a sorted array(say nums[]) and an integer (say target) as inputs. The elements in the sorted array might be repeated. You need to print the first and last occurrence of the target and print the index of first and last occurrence. Print -1, -1 if the target is not present.

Sample Test Cases:
Input 1:
nums = [5,7,7,8,8,10], target = 8
Output 1:
3,4

Input 2:
 nums = [5,7,7,8,8,10], target = 6
Output 2:
-1,-1

Input 3:
 nums = [5,7,7,8,8,10], target = 10
Output 3:
5,5
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// binary search for the first (findFirst = 1) or last (findFirst = 0) index of target
int search(int nums[], int n, int target, int findFirst) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            result = mid;
            if (findFirst) high = mid - 1;   // keep looking on the left
            else low = mid + 1;              // keep looking on the right
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    char line[2000];
    int values[501], count = 0;
    fgets(line, sizeof(line), stdin);

    // input looks like: nums = [5,7,7,8,8,10], target = 8
    // pick out every number; the last one is the target, the rest are the array
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

    int target = values[count - 1];
    int n = count - 1;
    int first = search(values, n, target, 1);
    int last = search(values, n, target, 0);
    printf("%d,%d\n", first, last);
    return 0;
}
