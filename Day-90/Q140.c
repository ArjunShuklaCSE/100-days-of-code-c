/*
Q140: Define a struct with enum Gender and print person's gender.

Sample Test Cases:
Input 1:
Gender=MALE
Output 1:
Male
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Gender { MALE, FEMALE, OTHER };

struct Person {
    enum Gender gender;
};

int main() {
    const char *names[] = { "MALE", "FEMALE", "OTHER" };
    const char *labels[] = { "Male", "Female", "Other" };
    char line[100] = "", word[20] = "";
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';

    // input looks like: Gender=MALE  (or just: MALE)  -> the word after the =
    char *eq = strchr(line, '=');
    sscanf(eq != NULL ? eq + 1 : line, "%19s", word);
    for (int i = 0; word[i] != '\0'; i++) word[i] = (char)toupper((unsigned char)word[i]);

    // find which gender was typed; its position in names is its enum value
    int found = -1;
    for (int g = MALE; g <= OTHER; g++) {
        if (strcmp(word, names[g]) == 0) found = g;
    }
    if (found == -1) {
        printf("Unknown gender: enter MALE, FEMALE or OTHER\n");
        return 1;
    }

    struct Person person;
    person.gender = (enum Gender)found;
    printf("%s\n", labels[person.gender]);
    return 0;
}
