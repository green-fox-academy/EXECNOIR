#include<stdio.h>

int main()
{
    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)
    //
    //  Use variables to store the informations!
    //
    //  Example output:
    //  John Doe
    //  31
    //  1.87
    char* name = "Gabor";
    int age = 31;
    float height = 1.81;


    printf("%s\n%d\n%.2f\n ", name, age, height);


    return 0;
}