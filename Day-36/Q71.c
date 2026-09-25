/*
Q71: Read and print a matrix.

Sample Test Cases:
Input 1:
2 2
1 2
3 4
Output 1:
1 2
3 4
*/

#include <stdio.h>

int main() {
    int r, c, a[10][10];
    scanf("%d %d", &r, &c);
    if (r < 1 || r > 10 || c < 1 || c > 10) {
        printf("Invalid size\n");
        return 0;
    }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d", a[i][j]);
            if (j < c - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
