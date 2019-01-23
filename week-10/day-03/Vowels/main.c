#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int count_vowels();

/*
 * Vowels:
 *
 * Create a function that can count the vowels in the text.txt.
 *
 * text.txt example:
 * Lorem ipsum dolor sit etc.
 *
 * In the same function write the vowels into another text file (just_some_vowels.txt).
 *
 * just_some_vowels.txt example solution:
 * oeiuooi etc.
 *
 * The function should return with a number of the vowels. (101)
 */

int main()
{
    count_vowels();
    return 0;
}

int count_vowels()
{
    FILE* fp;
    fp = fopen("../text.txt", "r");
    FILE* f;
    f = fopen("../just_some_vowels.txt", "a");

    if(f == NULL){
        return NULL;
    }

    if(fp == NULL){
        return NULL;
    }
    int counter = 0;
    char text[256];
    while(fgets(text, 256, fp) != NULL)
    {
        for (int i = 0; i < strlen(text); ++i) {
            if(text[i]=='a' || text[i]=='e' || text[i]=='i' ||
               text[i]=='o' || text[i]=='u' || text[i]=='A' ||
               text[i]=='E' || text[i]=='I' || text[i]=='O' ||
               text[i]=='U')
            {

                fprintf(f, "%c", text[i]);
                ++counter;
            }
        }

    }


    return counter;
}