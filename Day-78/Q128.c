/*
Q128: Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters.

Sample Test Cases:
Input 1:
File: text.txt (Content: Welcome to C language)
Output 1:
Vowels: 8
Consonants: 10
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char line[300], name[100] = "";
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';

    // input looks like: File: text.txt (Content: ...)  or just: text.txt
    // -> the filename is the first word after the colon, if there is one
    char *colon = strchr(line, ':');
    sscanf(colon != NULL ? colon + 1 : line, "%99s", name);

    FILE *file = fopen(name, "r");
    if (file == NULL) {
        printf("Error: File does not exist!\n");
        return 1;
    }

    // only letters count: a vowel is one of a e i o u, any other letter is a consonant
    int vowels = 0, consonants = 0, c;
    while ((c = fgetc(file)) != EOF) {
        if (!isalpha(c)) continue;
        if (strchr("aeiou", tolower(c)) != NULL) {
            vowels++;
        } else {
            consonants++;
        }
    }
    fclose(file);

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    return 0;
}
