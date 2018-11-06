#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;

    int *aMemory = &a;
    int *bMemory = &b;

    int c = *aMemory + *bMemory;

    std::cout << c << std::endl;

    return 0;
}