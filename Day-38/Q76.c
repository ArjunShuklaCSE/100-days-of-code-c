/*
Q76: Check if a matrix is symmetric.

Sample Test Cases:
Input 1:
2 2
1 2
2 1
Output 1:
True

Input 2:
2 2
1 0
2 1
Output 2:
False
*/

#include <stdio.h>

int main() {
    int r, c, a[10][10], symmetric = 1;
    scanf("%d %d", &r, &c);
    if (r < 1 || r > 10 || c < 1 || c > 10) {
        printf("Invalid size\n");
        return 0;
    }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    if (r != c) symmetric = 0;
    for (int i = 0; i < r && symmetric; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] != a[j][i]) {
                symmetric = 0;
                break;
            }
        }
    }
    if (symmetric) printf("True\n");
    else printf("False\n");
    return 0;
}
