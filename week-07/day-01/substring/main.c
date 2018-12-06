#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substring(char *string1, char *string2);

int main() {
    char *string1;
    char *string2;
    printf("Give me a string.\n");
    scanf("%s", string1);
    printf("Give me another.\n");
    scanf("%s", string2);


    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the shorter string is a substring of the longer one and
    // returns 0 otherwise
    // If the two strings has the same lenght than the function should return -1

    return 0;
}

int substring(char *string1, char *string2) {
    if (strlen(string1) == strlen(string2)) {
        return -1;
    } else if (strlen(string1) > strlen(string2)) {
        for (int i = 0; string1[i]; ++i) {
            if (string1[i] == string2[0]) {
                int counter = i;
                for (; string1[i]; ++i) {
                    if ((string1[i] != string2[counter]) && (i != strlen(string1) - 1) {
                        return 0;
                    } else if (i == stlen(string1) - 1) {
                        return 1;
                    }

                }
            }
        }
    }
}
