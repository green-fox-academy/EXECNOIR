#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// create a program which asks for full name and age
// and stores it in a char array
// parse that array to first_name, last_name, age (use tokenizing)
// print out the the stored variables
// example:
//   printf("Your name is: %s %s and you are %d years old", first_name, last_name, age);

int parse_data(char* data);

int main ()
{
    char user_data[255];
    printf("What is your name and how old are you?\n");
    gets(user_data);
    parse_data(user_data);

    return 0;
}
int parse_data(char* data)
{
    char* token = strtok(data, " ");
    char* first_name = token;
    token = strtok(NULL, " ");
    char* last_name = token;
    token = strtok(NULL, " ");
    char* age = token;
    int agenumber = atoi(age);

    printf("Your name is: %s\n %s\n and you are %d years old", first_name, last_name, agenumber);
    return 1;
}