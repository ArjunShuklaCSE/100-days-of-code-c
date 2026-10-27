/*
Q129: A file numbers.txt contains a list of integers separated by spaces. Read all integers, compute their sum and average, and print both.

Sample Test Cases:
Input 1:
File: numbers.txt (Content: 10 20 30 40 50)
Output 1:
Sum = 150
Average = 30.00
*/

#include <stdio.h>
#include <string.h>

int main() {
    char line[300], name[100] = "numbers.txt";
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';

    // input looks like: File: numbers.txt (Content: ...)  or just: numbers.txt
    // -> the filename is the first word after the colon; with no input it stays numbers.txt
    char *colon = strchr(line, ':');
    sscanf(colon != NULL ? colon + 1 : line, "%99s", name);

    FILE *file = fopen(name, "r");
    if (file == NULL) {
        printf("Error: File does not exist!\n");
        return 1;
    }

    // fscanf skips the spaces and newlines between numbers and returns 1 for each number it reads
    long long sum = 0, value;
    int count = 0;
    while (fscanf(file, "%lld", &value) == 1) {
        sum += value;
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("No numbers in %s\n", name);
        return 0;
    }
    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", (double)sum / count);
    return 0;
}
