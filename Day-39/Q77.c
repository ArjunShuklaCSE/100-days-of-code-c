/*
Q77: Check if the elements on the diagonal of a matrix are distinct.

Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 1
Output 1:
False

Input 2:
3 3
1 2 3
4 5 6
7 8 9
Output 2:
True
*/

#include <stdio.h>

int main() {
    int r, c, a[10][10], distinct = 1;
    scanf("%d %d", &r, &c);
    if (r < 1 || r > 10 || c < 1 || c > 10) {
        printf("Invalid size\n");
        return 0;
    }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    int size = r < c ? r : c;
    for (int i = 0; i < size && distinct; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i][i] == a[j][j]) {
                distinct = 0;
                break;
            }
        }
    }
    if (distinct) printf("True\n");
    else printf("False\n");
    return 0;
}
