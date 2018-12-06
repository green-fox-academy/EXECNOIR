#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int sameString(char* string1, char* string2);

int main()
{
    char string1[10];
    char string2[10];
    printf("Give me two short strings!\n");
    scanf("%s", string1);
    for (int i = 0; i < string1[i] ; ++i) {
        string1[i] = tolower(string1[i]);
    }
    scanf("%s", string2);
    for (int i = 0; i < string2[i] ; ++i) {
        string2[i] = tolower(string2[i]);
    }

    if(sameString(string1, string2)){
        printf("They are equal");
    }else{
        printf("They are not equal");
    }

    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    return 0;
}
int sameString(char* string1, char* string2)
{
    if(!strcmp(string1, string2)){
        return 1;
    }else{
        return 0;
    }
}