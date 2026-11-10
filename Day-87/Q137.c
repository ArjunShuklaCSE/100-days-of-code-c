/*
Q137: Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.

Sample Test Cases:
Input 1:
GUEST
Output 1:
Welcome Guest!
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Role { ADMIN, USER, GUEST };

int main() {
    const char *names[] = { "ADMIN", "USER", "GUEST" };
    char word[20] = "";
    scanf("%19s", word);
    for (int i = 0; word[i] != '\0'; i++) word[i] = (char)toupper((unsigned char)word[i]);

    // find which role was typed; its position in names is its enum value
    int found = -1;
    for (int r = ADMIN; r <= GUEST; r++) {
        if (strcmp(word, names[r]) == 0) found = r;
    }
    if (found == -1) {
        printf("Unknown role: enter ADMIN, USER or GUEST\n");
        return 1;
    }

    switch ((enum Role)found) {
        case ADMIN: printf("Welcome Admin!\n"); break;
        case USER:  printf("Welcome User!\n");  break;
        case GUEST: printf("Welcome Guest!\n"); break;
    }
    return 0;
}
