/*
Q125: Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.

Sample Test Cases:
Input 1:
Existing File: data.txt (Content before execution: Hello world)
User Input: This is appended text.
Output 1:
File updated successfully with appended text.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char line[300], name[100] = "", text[300] = "";

    // first line: Existing File: data.txt (...)  or just: data.txt
    // -> the filename is the first word after the colon, if there is one
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';
    char *colon = strchr(line, ':');
    sscanf(colon != NULL ? colon + 1 : line, "%99s", name);

    // second line: User Input: This is appended text.  -> the text is everything after the colon
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';
    line[strcspn(line, "\r\n")] = '\0';
    colon = strchr(line, ':');
    char *start = colon != NULL ? colon + 1 : line;
    while (*start == ' ') start++;
    strcpy(text, start);

    // the file has to exist already, so check by opening it for reading first,
    // and look at its last character so the new text goes on a line of its own
    FILE *file = fopen(name, "rb");
    if (file == NULL) {
        printf("Error: File does not exist!\n");
        return 1;
    }
    int needsNewline = 0;
    if (fseek(file, -1, SEEK_END) == 0 && fgetc(file) != '\n') needsNewline = 1;
    fclose(file);

    // "a" always writes at the end, so the existing content is never overwritten
    file = fopen(name, "a");
    if (file == NULL) {
        printf("Error: could not open %s for appending\n", name);
        return 1;
    }
    if (needsNewline) fputc('\n', file);
    fprintf(file, "%s\n", text);
    fclose(file);

    printf("File updated successfully with appended text.\n");
    return 0;
}
