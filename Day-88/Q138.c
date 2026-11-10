/*
Q138: Print all enum names and integer values using a loop.

Sample Test Cases:
Input 1:
No input
Output 1:
RED=0
YELLOW=1
GREEN=2
*/

#include <stdio.h>

enum Color { RED, YELLOW, GREEN };

int main() {
    // an enum only stores numbers, so the names to print are kept in an array in the same order
    const char *names[] = { "RED", "YELLOW", "GREEN" };

    for (enum Color c = RED; c <= GREEN; c++) {
        printf("%s=%d\n", names[c], c);
    }
    return 0;
}
