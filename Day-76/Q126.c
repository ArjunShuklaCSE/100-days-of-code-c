/*
Q126: Ask the user for a filename. Check if it exists by trying to open it in read mode. If the file pointer is NULL, print an error message; otherwise, read and display its content.

Sample Test Cases:
Input 1:
Filename: sample.txt (File Exists: Yes)
Output 1:
File opened successfully.
(Displays file content)

Input 2:
Filename: nofile.txt (File Exists: No)
Output 2:
Error: File does not exist!
*/

#include <stdio.h>
#include <string.h>

int main() {
    char line[300], name[100] = "", text[500];
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';

    // input looks like: Filename: sample.txt (...)  or just: sample.txt
    // -> the filename is the first word after the colon, if there is one
    char *colon = strchr(line, ':');
    sscanf(colon != NULL ? colon + 1 : line, "%99s", name);

    // fopen gives back NULL when the file can't be opened for reading
    FILE *file = fopen(name, "r");
    if (file == NULL) {
        printf("Error: File does not exist!\n");
        return 1;
    }

    printf("File opened successfully.\n");
    while (fgets(text, sizeof(text), file) != NULL) {
        printf("%s", text);
    }
    fclose(file);
    return 0;
}
