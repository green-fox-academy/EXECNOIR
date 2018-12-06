#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_between_chars(char *word);

int main() {

    // Create a function which takes a string as a parameter and
    // returns the number of characters between two repeating characters
    // the repeating char can be a local variable in the function itself or
    // it can be passed to the function as parameter

    char *word = "Programming";

    // the output should be: 6 (in this case the repeating char was 'g')
    printf("%d", count_between_chars(word));

    return 0;
}

int count_between_chars(char *word) {
    int num = 0;
    int counter = 0;
    char repeat = 'g';
    for (int i = 0; word[i]; ++i) {
        if (word[i] == repeat) {
            num = i + 1;
            break;
        }
    }
    for (; word[num] != '\0'; num++) {

        if (word[num] == repeat) {
            return counter;
        }
        counter = counter + 1;
    }
}
