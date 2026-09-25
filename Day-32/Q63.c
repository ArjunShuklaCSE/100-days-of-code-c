/*
Q63: Merge two arrays.

Sample Test Cases:
Input 1:
3
1 2 3
2
4 5
Output 1:
1 2 3 4 5
*/

#include <stdio.h>

int main() {
    int n1, n2, a[100], b[100], merged[200];
    scanf("%d", &n1);
    if (n1 < 0 || n1 > 100) {
        printf("Invalid size\n");
        return 0;
    }
    for (int i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &n2);
    if (n2 < 0 || n2 > 100) {
        printf("Invalid size\n");
        return 0;
    }
    for (int i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n1; i++) {
        merged[i] = a[i];
    }
    for (int i = 0; i < n2; i++) {
        merged[n1 + i] = b[i];
    }
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d", merged[i]);
        if (i < n1 + n2 - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
