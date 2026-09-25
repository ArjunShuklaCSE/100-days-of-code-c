/*
Q74: Find the transpose of a matrix.

Sample Test Cases:
Input 1:
2 3
1 2 3
4 5 6
Output 1:
1 4
2 5
3 6
*/

#include <stdio.h>

int main() {
    int r, c, a[10][10], t[10][10];
    scanf("%d %d", &r, &c);
    if (r < 1 || r > 10 || c < 1 || c > 10) {
        printf("Invalid size\n");
        return 0;
    }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            t[j][i] = a[i][j];
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d", t[i][j]);
            if (j < r - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
