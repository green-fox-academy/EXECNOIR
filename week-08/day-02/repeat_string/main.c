#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.
char* makes_string();
char* repeat_string(char* str, int number);

int main()
{


    printf("%s", repeat_string(makes_string(), 10));
    return 0;
}

char* makes_string()
{
    int c = 0;
    int size = 1;
    char* str = malloc(1);
    str[0] = '\0';
    printf("%s", "Gibe word: \n");
    while((char)c != '\n') {
        c = getchar();
        if (c != '\n') {
            str = realloc(str, size+1);
            str[size-1] = (char) c;
            str[size] = '\0';
            size++;

        }
    }
    return str;
}
char* repeat_string(char* str, int number)
{
    char* result = calloc(strlen(str)*number + 1, sizeof(char));
    for (int i = 0; i < number; ++i) {
        strcat(result, str);
    }
    return result;
}