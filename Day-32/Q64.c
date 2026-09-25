/*
Q64: Find the digit that occurs the most times in an integer number.

Sample Test Cases:
Input 1:
112233
Output 1:
1

Input 2:
887799
Output 2:
7
*/

#include <stdio.h>

int main() {
    int n, count[10] = {0};
    scanf("%d", &n);
    if (n < 0) n = -n;
    if (n == 0) count[0] = 1;
    while (n > 0) {
        count[n % 10]++;
        n /= 10;
    }
    int best = 0;
    for (int d = 1; d <= 9; d++) {
        if (count[d] > count[best]) best = d;   // on a tie the smaller digit wins
    }
    printf("%d\n", best);
    return 0;
}
