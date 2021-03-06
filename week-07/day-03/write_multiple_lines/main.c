#include <stdio.h>
#include <string.h>

// Create a function that takes 3 parameters: a path, a word and a number,
// than it should write to a file.
// The path parameter should describes the location of the file.
// The word parameter should be a string, that will be written to the file as lines
// The number paramter should describe how many lines the file should have.
// So if the word is "apple" and the number is 5, than it should write 5 lines
// to the file and each line should be "apple"

int write_multiple_lines(char* path, char* word, int number);

int main()
{
    write_multiple_lines("../my-file.txt", "\napple", 4);

    return 0;
}
int write_multiple_lines(char* path, char* word, int number)
{
    FILE* fptr = fopen(path, "a+");
    if(!fptr){
        return 0;
    }
    for (int i = 1; i < number; ++i) {
        fputs(word, fptr);
    }
    return 1;
}