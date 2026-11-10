/*
Q139: Show that enums store integers by printing assigned values.

Sample Test Cases:
Input 1:
No input
Output 1:
SUCCESS=0, FAILURE=1, TIMEOUT=2
*/

#include <stdio.h>

enum Status { SUCCESS, FAILURE, TIMEOUT };

int main() {
    // each enum constant is just an int, so it prints with %d like any other integer
    int values[] = { SUCCESS, FAILURE, TIMEOUT };
    printf("SUCCESS=%d, FAILURE=%d, TIMEOUT=%d\n", values[0], values[1], values[2]);
    return 0;
}
