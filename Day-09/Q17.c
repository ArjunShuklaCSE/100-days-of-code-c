/*
Q17: Write a program to find the roots of a quadratic equation and categorize them.

Sample Test Cases:
Input 1:
1 -3 2
Output 1:
Roots are real and different: 2, 1

Input 2:
1 -2 1
Output 2:
Roots are real and same: 1

Input 3:
1 2 5
Output 3:
Roots are complex
*/

#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a == 0) {
        printf("Not a quadratic equation\n");
        return 0;
    }
    double d = b * b - 4 * a * c;
    if (d > 0) {
        double r1 = (-b + sqrt(d)) / (2 * a);
        double r2 = (-b - sqrt(d)) / (2 * a);
        printf("Roots are real and different: %g, %g\n", r1, r2);
    } else if (d == 0) {
        printf("Roots are real and same: %g\n", -b / (2 * a));
    } else {
        printf("Roots are complex\n");
    }
    return 0;
}
