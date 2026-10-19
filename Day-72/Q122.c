/*
Q122: Write a C program that opens an existing file (e.g., info.txt) and reads its contents using fgets(). The program should print all the lines to the console until EOF (end of file) is reached.

Sample Test Cases:
Input 1:
File: info.txt (Content: Name: Rahul\nAge: 23)
Output 1:
Name: Rahul
Age: 23
*/

#include <stdio.h>

int main() {
    char line[500];

    // info.txt is the file Q121 writes; run that first to create it
    FILE *file = fopen("info.txt", "r");
    if (file == NULL) {
        printf("Could not open info.txt\n");
        return 1;
    }

    // fgets returns NULL once it reaches the end of the file
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
    return 0;
}
