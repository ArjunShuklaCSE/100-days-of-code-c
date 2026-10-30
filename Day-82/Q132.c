/*
Q132: Define an enum for traffic lights (RED, YELLOW, GREEN) and print 'Stop', 'Wait', or 'Go' based on its value.

Sample Test Cases:
Input 1:
GREEN
Output 1:
Go
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Light { RED, YELLOW, GREEN };

int main() {
    char word[20] = "";
    scanf("%19s", word);
    for (int i = 0; word[i] != '\0'; i++) word[i] = (char)toupper((unsigned char)word[i]);

    // turn the typed word into its enum value
    enum Light light;
    if (strcmp(word, "RED") == 0) {
        light = RED;
    } else if (strcmp(word, "YELLOW") == 0) {
        light = YELLOW;
    } else if (strcmp(word, "GREEN") == 0) {
        light = GREEN;
    } else {
        printf("Unknown light: enter RED, YELLOW or GREEN\n");
        return 1;
    }

    switch (light) {
        case RED:    printf("Stop\n"); break;
        case YELLOW: printf("Wait\n"); break;
        case GREEN:  printf("Go\n");   break;
    }
    return 0;
}
