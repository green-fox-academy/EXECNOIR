#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter,
// and splits a string to words by space
// solve the problem with the proper string.h function

int splits_sentence(char* sentence);

int main()
{
    printf("Type in a sentence:\n\n");
    char string[256];
    gets(string);
    splits_sentence(string);

    return(0);
}

int splits_sentence(char* sentence)
{
    char d[2]= " ";
    char* p = strtok(sentence, d);

    while( p != NULL ) {
        printf( "%s\n", p );

        p = strtok(NULL, d);
    }
    return 1;
}