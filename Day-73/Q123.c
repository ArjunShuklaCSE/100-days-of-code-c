/*
Q123: Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.

Sample Test Cases:
Input 1:
File: sample.txt (Content: Hello world\nThis is C programming)
Output 1:
Characters: 31
Words: 5
Lines: 2
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char line[300], name[100] = "";
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';

    // input looks like: File: sample.txt (Content: ...)  or just: sample.txt
    // -> the filename is the first word after the colon, if there is one
    char *colon = strchr(line, ':');
    sscanf(colon != NULL ? colon + 1 : line, "%99s", name);

    FILE *file = fopen(name, "r");
    if (file == NULL) {
        printf("Error: File does not exist!\n");
        return 1;
    }

    // a new word starts at every non-space character that comes right after a space (or the start)
    long chars = 0, words = 0, lines = 0;
    int c, prev = '\n', inWord = 0;
    while ((c = fgetc(file)) != EOF) {
        chars++;
        if (c == '\n') lines++;
        if (isspace(c)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            words++;
        }
        prev = c;
    }
    fclose(file);
    if (chars > 0 && prev != '\n') lines++;   // the last line has no newline after it

    printf("Characters: %ld\n", chars);
    printf("Words: %ld\n", words);
    printf("Lines: %ld\n", lines);
    return 0;
}
