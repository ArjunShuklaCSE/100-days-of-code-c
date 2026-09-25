/*
Q69: Find the second largest element in an array.

Sample Test Cases:
Input 1:
5
10 20 30 40 50
Output 1:
40
*/

#include <stdio.h>

int main() {
    int n, arr[100];
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Invalid size\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int largest = arr[0], second = 0, found = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
            found = 1;
        } else if (arr[i] < largest && (!found || arr[i] > second)) {
            second = arr[i];
            found = 1;
        }
    }
    if (found) {
        printf("%d\n", second);
    } else {
        printf("No second largest element\n");
    }
    return 0;
}
