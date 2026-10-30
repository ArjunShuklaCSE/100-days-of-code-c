/*
Q131: Create an enumeration for days (SUNDAY to SATURDAY) and print each day with its integer value.

Sample Test Cases:
Input 1:
No input
Output 1:
SUNDAY = 0
MONDAY = 1
TUESDAY = 2
WEDNESDAY = 3
THURSDAY = 4
FRIDAY = 5
SATURDAY = 6
*/

#include <stdio.h>

// with no values given, the first name is 0 and each one after it is one more
enum Day { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };

int main() {
    // an enum only stores numbers, so the names to print are kept in an array in the same order
    const char *names[] = { "SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY" };

    for (enum Day d = SUNDAY; d <= SATURDAY; d++) {
        printf("%s = %d\n", names[d], d);
    }
    return 0;
}
