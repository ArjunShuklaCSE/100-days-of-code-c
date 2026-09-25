/*
Q5: Write a program to convert temperature from Celsius to Fahrenheit.

Sample Test Cases:
Input 1:
0
Output 1:
Fahrenheit=32

Input 2:
100
Output 2:
Fahrenheit=212
*/

#include <stdio.h>

int main() {
    float celsius;
    scanf("%f", &celsius);
    float fahrenheit = celsius * 9 / 5 + 32;
    printf("Fahrenheit=%g\n", fahrenheit);
    return 0;
}
