/*
Q142: Store details of 5 students in an array of structures and print all.

Sample Test Cases:
Input 1:
Details of 5 students (Name, Roll, Marks)
Output 1:
Tabular list of all 5 students with their details
*/

#include <stdio.h>

#define COUNT 5

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

int main() {
    struct Student students[COUNT];

    // input: one student per line, like: Asha 101 90  (a name has to be one word)
    for (int i = 0; i < COUNT; i++) {
        if (scanf("%49s %d %d", students[i].name, &students[i].roll_no, &students[i].marks) != 3) {
            printf("Enter 5 students, one per line, like: Asha 101 90\n");
            return 1;
        }
    }

    // %-10s pads the name to 10 characters on the left, so the columns line up
    printf("%-4s %-10s %-6s %s\n", "No.", "Name", "Roll", "Marks");
    for (int i = 0; i < COUNT; i++) {
        printf("%-4d %-10s %-6d %d\n", i + 1, students[i].name, students[i].roll_no, students[i].marks);
    }
    return 0;
}
