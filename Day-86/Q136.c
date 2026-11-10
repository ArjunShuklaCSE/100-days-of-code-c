/*
Q136: Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.

Sample Test Cases:
Input 1:
ADD 10 20
Output 1:
30
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Choice { ADD, SUBTRACT, MULTIPLY };

int main() {
    const char *names[] = { "ADD", "SUBTRACT", "MULTIPLY" };
    char word[20] = "";
    long long a, b;
    if (scanf("%19s %lld %lld", word, &a, &b) != 3) {
        printf("Enter a choice and two numbers, like: ADD 10 20\n");
        return 1;
    }
    for (int i = 0; word[i] != '\0'; i++) word[i] = (char)toupper((unsigned char)word[i]);

    // find which choice was typed; its position in names is its enum value
    int found = -1;
    for (int c = ADD; c <= MULTIPLY; c++) {
        if (strcmp(word, names[c]) == 0) found = c;
    }
    if (found == -1) {
        printf("Unknown choice: enter ADD, SUBTRACT or MULTIPLY\n");
        return 1;
    }

    switch ((enum Choice)found) {
        case ADD:      printf("%lld\n", a + b); break;
        case SUBTRACT: printf("%lld\n", a - b); break;
        case MULTIPLY: printf("%lld\n", a * b); break;
    }
    return 0;
}
