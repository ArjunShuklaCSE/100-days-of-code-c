/*
Q121: Write a C program that creates a text file named info.txt in write mode. The program should take the user’s name and age as input, and write them to the file using fprintf(). After writing, display a message confirming that the data was successfully saved.

Sample Test Cases:
Input 1:
Name: Rahul, Age: 23
Output 1:
File created successfully! Data written to info.txt
*/

#include <stdio.h>
#include <string.h>

int main() {
    char line[200], name[100] = "";
    int age = 0;
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';

    // input looks like: Name: Rahul, Age: 23  (or just: Rahul 23)
    if (sscanf(line, " Name: %99[^,], Age: %d", name, &age) != 2 &&
        sscanf(line, "%99s %d", name, &age) != 2) {
        printf("Enter a name and an age, like: Name: Rahul, Age: 23\n");
        return 1;
    }

    // "w" creates info.txt, or empties it if it already exists
    FILE *file = fopen("info.txt", "w");
    if (file == NULL) {
        printf("Could not create info.txt\n");
        return 1;
    }
    fprintf(file, "Name: %s\n", name);
    fprintf(file, "Age: %d\n", age);
    fclose(file);

    printf("File created successfully! Data written to info.txt\n");
    return 0;
}
