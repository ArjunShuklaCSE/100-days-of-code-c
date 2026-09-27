/*
Q98: Print initials of a name with the surname displayed in full.

Sample Test Cases:
Input 1:
John David Doe
Output 1:
J.D. Doe
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[1000];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    // remove trailing spaces, then find where the surname (last word) starts
    int end = strlen(name);
    while (end > 0 && name[end - 1] == ' ') end--;
    name[end] = '\0';
    int last = end;
    while (last > 0 && name[last - 1] != ' ') last--;

    for (int i = 0; i < last; i++) {
        if (name[i] != ' ' && (i == 0 || name[i - 1] == ' ')) {
            printf("%c.", toupper(name[i]));
        }
    }
    if (last > 0) printf(" ");
    printf("%s\n", name + last);
    return 0;
}
