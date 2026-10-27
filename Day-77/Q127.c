/*
Q127: Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.

Sample Test Cases:
Input 1:
Input File (input.txt): Hello World\nC programming
Output 1:
Output File (output.txt): HELLO WORLD\nC PROGRAMMING
*/

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Error: input.txt does not exist!\n");
        return 1;
    }
    FILE *out = fopen("output.txt", "w");
    if (out == NULL) {
        fclose(in);
        printf("Error: could not create output.txt\n");
        return 1;
    }

    // toupper changes only lowercase letters; everything else is copied as it is
    int c;
    while ((c = fgetc(in)) != EOF) {
        fputc(toupper(c), out);
    }
    fclose(in);
    fclose(out);

    printf("Converted input.txt to uppercase and saved it to output.txt\n");
    return 0;
}
