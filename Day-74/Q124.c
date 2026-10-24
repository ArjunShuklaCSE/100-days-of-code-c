/*
Q124: Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().

Sample Test Cases:
Input 1:
Source File: source.txt (Content: Learning C File Handling)
Output 1:
File copied successfully to destination.txt
*/

#include <stdio.h>
#include <string.h>

// input lines look like: Source File: source.txt (Content: ...)  or just: source.txt
// -> the filename is the first word after the colon, if there is one
int readFilename(char name[]) {
    char line[300];
    name[0] = '\0';
    if (fgets(line, sizeof(line), stdin) == NULL) return 0;
    char *colon = strchr(line, ':');
    return sscanf(colon != NULL ? colon + 1 : line, "%99s", name) == 1;
}

int main() {
    char source[100], destination[100];
    readFilename(source);
    // the sample only gives the source, so the destination defaults to destination.txt
    if (!readFilename(destination)) strcpy(destination, "destination.txt");

    FILE *in = fopen(source, "r");
    if (in == NULL) {
        printf("Error: %s does not exist!\n", source);
        return 1;
    }
    FILE *out = fopen(destination, "w");
    if (out == NULL) {
        fclose(in);
        printf("Error: could not create %s\n", destination);
        return 1;
    }

    // copy one character at a time until the end of the source file
    int c;
    while ((c = fgetc(in)) != EOF) {
        fputc(c, out);
    }
    fclose(in);
    fclose(out);

    printf("File copied successfully to %s\n", destination);
    return 0;
}
