/*
Q79: Perform diagonal traversal of a matrix.

Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 9
Output 1:
1 2 4 7 5 3 6 8 9
*/

#include <stdio.h>

int main() {
    int r, c, a[10][10], first = 1;
    scanf("%d %d", &r, &c);
    if (r < 1 || r > 10 || c < 1 || c > 10) {
        printf("Invalid size\n");
        return 0;
    }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    // walk each anti-diagonal (i + j = d), alternating direction (zigzag)
    for (int d = 0; d <= r + c - 2; d++) {
        int top = d - c + 1 > 0 ? d - c + 1 : 0;   // smallest row on this diagonal
        int bottom = d < r - 1 ? d : r - 1;         // largest row on this diagonal
        if (d % 2 == 0) {
            for (int i = bottom; i >= top; i--) {
                if (!first) printf(" ");
                printf("%d", a[i][d - i]);
                first = 0;
            }
        } else {
            for (int i = top; i <= bottom; i++) {
                if (!first) printf(" ");
                printf("%d", a[i][d - i]);
                first = 0;
            }
        }
    }
    printf("\n");
    return 0;
}
