/*
Q143: Find and print the student with the highest marks.

Sample Test Cases:
Input 1:
3 students: Ravi 101 95, Sita 102 85, Aman 103 88
Output 1:
Topper: Ravi (Marks: 95)
*/

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

int main() {
    struct Student students[100];
    int n = 0, used;
    char line[4000];
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';

    // input looks like: 3 students: Ravi 101 95, Sita 102 85, Aman 103 88
    // -> skip past the colon, then read "name roll marks" records separated by commas
    char *colon = strchr(line, ':');
    char *p = colon != NULL ? colon + 1 : line;
    while (n < 100 && sscanf(p, " %49[^ ,] %d %d%n", students[n].name, &students[n].roll_no, &students[n].marks, &used) == 3) {
        n++;
        p += used;
        while (*p == ',' || *p == ' ') p++;
    }
    if (n == 0) {
        printf("No students found\n");
        return 1;
    }

    // keep the first student with the highest marks seen so far
    int top = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].marks > students[top].marks) top = i;
    }
    printf("Topper: %s (Marks: %d)\n", students[top].name, students[top].marks);
    return 0;
}
