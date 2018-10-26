#include <iostream>

int main(int argc, char* args[]) {

    // Swap the values of the variables
    int a = 123;
    int b = 526;

    std::cout << "Before swap." << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    int c = a;
    a = b;
    b = c;

    std::cout << "After swap" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    return 0;
}