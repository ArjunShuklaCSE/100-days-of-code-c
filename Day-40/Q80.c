/*
Q80: Multiply two matrices.

Sample Test Cases:
Input 1:
2 3
1 2 3
4 5 6
3 2
7 8
9 10
11 12
Output 1:
58 64
139 154
*/

#include <stdio.h>

int main() {
    int r1, c1, r2, c2, a[10][10], b[10][10], result[10][10];
    scanf("%d %d", &r1, &c1);
    if (r1 < 1 || r1 > 10 || c1 < 1 || c1 > 10) {
        printf("Invalid size\n");
        return 0;
    }
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);
    scanf("%d %d", &r2, &c2);
    if (c1 != r2 || c2 < 1 || c2 > 10) {
        printf("Matrices cannot be multiplied\n");
        return 0;
    }
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d", result[i][j]);
            if (j < c2 - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
