/*
Q133: Create an enum for months and print how many days each month has.

Sample Test Cases:
Input 1:
FEB
Output 1:
28 or 29 days
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Month { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

int main() {
    const char *names[] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
    char word[20] = "";
    scanf("%19s", word);
    for (int i = 0; word[i] != '\0'; i++) word[i] = (char)toupper((unsigned char)word[i]);

    // find which month was typed; its position in names is its enum value
    int found = -1;
    for (int m = JAN; m <= DEC; m++) {
        if (strncmp(word, names[m], 3) == 0) found = m;   // first 3 letters, so FEBRUARY works too
    }
    if (found == -1) {
        printf("Unknown month: enter JAN, FEB, ... DEC\n");
        return 1;
    }

    enum Month month = (enum Month)found;
    switch (month) {
        case FEB:
            printf("28 or 29 days\n");
            break;
        case APR: case JUN: case SEP: case NOV:
            printf("30 days\n");
            break;
        default:
            printf("31 days\n");
    }
    return 0;
}
