#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";
    int *aMemory = &a;
    double *bMemory = &b;
    std::string *nameMemory = &name;


    std::cout << aMemory << std::endl;
    std::cout << bMemory << std::endl;
    std::cout << nameMemory << std::endl;

    return 0;
}