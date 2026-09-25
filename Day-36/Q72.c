/*
Q72: Find the sum of all elements in a matrix.

Sample Test Cases:
Input 1:
2 3
1 2 3
4 5 6
Output 1:
21
*/

#include <stdio.h>

int main() {
    int r, c, a[10][10], sum = 0;
    scanf("%d %d", &r, &c);
    if (r < 1 || r > 10 || c < 1 || c > 10) {
        printf("Invalid size\n");
        return 0;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
            sum += a[i][j];
        }
    }
    printf("%d\n", sum);
    return 0;
}
