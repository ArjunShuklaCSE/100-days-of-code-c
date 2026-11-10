/*
Q141: Define a structure Student with name, roll_no, and marks, then read and print one student's data.

Sample Test Cases:
Input 1:
Name: Asha
Roll: 101
Marks: 90
Output 1:
Name: Asha | Roll: 101 | Marks: 90
*/

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

// returns the text after the colon on a line like "Name: Asha", or the whole line if there's no colon
char *afterColon(char *line) {
    line[strcspn(line, "\r\n")] = '\0';
    char *colon = strchr(line, ':');
    char *p = colon != NULL ? colon + 1 : line;
    while (*p == ' ') p++;
    return p;
}

int main() {
    struct Student s;
    char line[200];

    // input looks like three lines: Name: Asha / Roll: 101 / Marks: 90
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';
    strncpy(s.name, afterColon(line), sizeof(s.name) - 1);
    s.name[sizeof(s.name) - 1] = '\0';

    if (fgets(line, sizeof(line), stdin) == NULL ||
        sscanf(afterColon(line), "%d", &s.roll_no) != 1) {
        printf("Enter the roll number on the second line, like: Roll: 101\n");
        return 1;
    }
    if (fgets(line, sizeof(line), stdin) == NULL ||
        sscanf(afterColon(line), "%d", &s.marks) != 1) {
        printf("Enter the marks on the third line, like: Marks: 90\n");
        return 1;
    }

    printf("Name: %s | Roll: %d | Marks: %d\n", s.name, s.roll_no, s.marks);
    return 0;
}
