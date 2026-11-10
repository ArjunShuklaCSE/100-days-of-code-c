/*
Q135: Assign explicit values starting from 10 and print them.

Sample Test Cases:
Input 1:
No input
Output 1:
A=10
B=11
C=12
*/

#include <stdio.h>

// only A is given a value; B and C keep counting up from it
enum Letters { A = 10, B, C };

int main() {
    printf("A=%d\n", A);
    printf("B=%d\n", B);
    printf("C=%d\n", C);
    return 0;
}
