#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int whereisIt(char* string, char c);

int main()
{
    char string[10];
    printf("Give me a short string.\n");
    scanf("%s", string);
    char c;
    printf("Give me a character.\n");
    scanf(" %c", &c);



    printf("%d", whereisIt(string, c));
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //

    return 0;
}

int whereisIt(char* string, char c)
{
    for (int i = 0; string[i] ; ++i) {
        if(string[i] == c){
            return i+1;
        }
    }
    return -1;
}