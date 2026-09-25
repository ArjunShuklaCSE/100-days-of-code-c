/*
Q59: Count even and odd numbers in an array.

Sample Test Cases:
Input 1:
6
1 2 3 4 5 6
Output 1:
Even=3, Odd=3

Input 2:
4
2 4 6 8
Output 2:
Even=4, Odd=0
*/

#include <stdio.h>

int main() {
    int n, arr[100], even = 0, odd = 0;
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Invalid size\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0) even++;
        else odd++;
    }
    printf("Even=%d, Odd=%d\n", even, odd);
    return 0;
}
