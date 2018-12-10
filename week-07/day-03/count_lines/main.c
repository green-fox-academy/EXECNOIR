#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file

int count_lines(char* file);

int main ()
{
    char file[15] = "../my-file.txt";
    printf("%d", count_lines(file));
    return 0;
}

int count_lines(char* file)
{
    FILE *fptr;
    fptr = fopen(file, "r");
    if(!fptr){
        return 0;
    }
    char text[100];

    int counter = 0;


    while(fgets(text, 100, fptr) != NULL){

        counter ++;

    }
    return counter;
}