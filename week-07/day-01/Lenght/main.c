#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nameLenght(char* name);

int main()
{
        char name[10];
        printf("Gibe name: \n");
        scanf("%s", name);



    printf("The lenght of your name is: %d\n", nameLenght(name));
    // Create a program which asks for the name of the user and stroes it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    return 0;
}
int nameLenght(char* name)
{
    int counter;
    for (int i = 0; name[i] != '\0' ; ++i) {

       counter = i;
    }
    return counter+1;
}