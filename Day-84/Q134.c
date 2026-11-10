/*
Q134: Define an enum with SUCCESS, FAILURE, and TIMEOUT, and print messages accordingly.

Sample Test Cases:
Input 1:
FAILURE
Output 1:
Operation failed
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Status { SUCCESS, FAILURE, TIMEOUT };

int main() {
    const char *names[] = { "SUCCESS", "FAILURE", "TIMEOUT" };
    char word[20] = "";
    scanf("%19s", word);
    for (int i = 0; word[i] != '\0'; i++) word[i] = (char)toupper((unsigned char)word[i]);

    // find which status was typed; its position in names is its enum value
    int found = -1;
    for (int s = SUCCESS; s <= TIMEOUT; s++) {
        if (strcmp(word, names[s]) == 0) found = s;
    }
    if (found == -1) {
        printf("Unknown status: enter SUCCESS, FAILURE or TIMEOUT\n");
        return 1;
    }

    switch ((enum Status)found) {
        case SUCCESS: printf("Operation successful\n"); break;
        case FAILURE: printf("Operation failed\n");     break;
        case TIMEOUT: printf("Operation timed out\n");  break;
    }
    return 0;
}
