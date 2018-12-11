#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.
char* makes_string();
char* concat(char* str1, char* str2);


int main()
{
    char* str1 = makes_string();
    char* str2 = makes_string();
    printf("%s", concat(str1, str2));

    return 0;
}
char* concat(char* str1, char* str2)
{
    char* concat = calloc(strlen(str1) + strlen(str2) + 1, sizeof(char) );
    strcat(concat,str1);
    strcat(concat,str2);
    return concat;
}

char* makes_string()
{
    int c = 0;
    int size = 1;
    char* str = malloc(1);
    str[0] = '\0';
    while((char)c != '\n') {
        c = getchar();
        if (c != '\n') {
            str = realloc(str, size+1);
            str[size-1] = (char) c;
            str[size] = '\0';
            size++;

        }
    }
    printf("%s\n", str);
    return str;
}