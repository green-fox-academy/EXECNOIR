#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* appenda(char* string);

int main()
{
    char string[10];
    printf("Give me a short string");
    scanf("%s", string);

    printf("%s", appenda(string));
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string

    return 0;
}

char* appenda(char string[10])
{
    string = strcat(string, "a");
    return string;
}