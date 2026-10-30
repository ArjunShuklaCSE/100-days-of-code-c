/*
Q130: Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.

Sample Test Cases:
Input 1:
Student 1 → Name: Asha, Roll: 101, Marks: 85; Student 2 → Name: Ravi, Roll: 102, Marks: 92
Output 1:
Name: Asha | Roll: 101 | Marks: 85
Name: Ravi | Roll: 102 | Marks: 92
*/

#include <stdio.h>
#include <string.h>

int main() {
    char line[2000], name[50];
    int roll, marks, stored = 0;
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';

    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error: could not create students.txt\n");
        return 1;
    }

    // input looks like: Name: Asha, Roll: 101, Marks: 85; Name: Ravi, ...  -> one record per "Name:"
    // each record goes into the file as one line: Asha 101 85
    for (char *p = strstr(line, "Name:"); p != NULL; p = strstr(p + 1, "Name:")) {
        if (sscanf(p, "Name: %49[^,], Roll: %d, Marks: %d", name, &roll, &marks) == 3) {
            fprintf(file, "%s %d %d\n", name, roll, marks);
            stored++;
        }
    }
    // without "Name:" labels, read plain records instead: Asha 101 85 Ravi 102 92
    if (stored == 0) {
        char *p = line;
        int used;
        while (sscanf(p, "%49s %d %d%n", name, &roll, &marks, &used) == 3) {
            fprintf(file, "%s %d %d\n", name, roll, marks);
            p += used;
        }
    }
    fclose(file);

    // read the records back; %s stops at a space, so a name has to be one word
    file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error: could not open students.txt\n");
        return 1;
    }
    while (fscanf(file, "%49s %d %d", name, &roll, &marks) == 3) {
        printf("Name: %s | Roll: %d | Marks: %d\n", name, roll, marks);
    }
    fclose(file);
    return 0;
}
