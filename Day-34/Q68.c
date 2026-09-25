/*
Q68: Delete an element from an array.

Sample Test Cases:
Input 1:
5
1 2 3 4 5
2
Output 1:
1 2 4 5
*/

#include <stdio.h>

int main() {
    int n, arr[100], pos;
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Invalid size\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &pos);   // pos is a 0-based index
    if (pos < 0 || pos >= n) {
        printf("Invalid position\n");
        return 0;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
