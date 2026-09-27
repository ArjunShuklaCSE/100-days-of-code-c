/*
Q97: Print the initials of a name.

Sample Test Cases:
Input 1:
John Doe
Output 1:
J.D.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[1000];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    for (int i = 0; name[i] != '\0'; i++) {
        // a letter starts a word if it's the first character or comes after a space
        if (name[i] != ' ' && (i == 0 || name[i - 1] == ' ')) {
            printf("%c.", toupper(name[i]));
        }
    }
    printf("\n");
    return 0;
}
