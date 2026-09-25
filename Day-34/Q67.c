/*
Q67: Insert an element in an array at a given position.

Sample Test Cases:
Input 1:
4
10 20 30 40
2 15
Output 1:
10 20 15 30 40
*/

#include <stdio.h>

int main() {
    int n, arr[101], pos, x;
    scanf("%d", &n);
    if (n < 0 || n > 100) {
        printf("Invalid size\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &pos, &x);   // pos is a 0-based index
    if (pos < 0 || pos > n) {
        printf("Invalid position\n");
        return 0;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = x;
    n++;
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
