/*
Q75: Add two matrices.

Sample Test Cases:
Input 1:
2 2
1 2
3 4
2 2
5 6
7 8
Output 1:
6 8
10 12
*/

#include <stdio.h>

int main() {
    int r1, c1, r2, c2, a[10][10], b[10][10];
    scanf("%d %d", &r1, &c1);
    if (r1 < 1 || r1 > 10 || c1 < 1 || c1 > 10) {
        printf("Invalid size\n");
        return 0;
    }
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);
    scanf("%d %d", &r2, &c2);
    if (r1 != r2 || c1 != c2) {
        printf("Matrices cannot be added\n");
        return 0;
    }
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("%d", a[i][j] + b[i][j]);
            if (j < c1 - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
