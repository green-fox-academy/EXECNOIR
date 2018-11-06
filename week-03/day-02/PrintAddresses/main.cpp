#include <iostream>

int main()
{
    int MyArray[5];

    std::cout << "Integer #1: " ;
    std::cin >> MyArray[0];
    std::cout << std::endl;

    std::cout << "Integer #2: " ;
    std::cin >> MyArray[1];
    std::cout << std::endl;

    std::cout << "Integer #3: " ;
    std::cin >> MyArray[2];
    std::cout << std::endl;

    std::cout << "Integer #4: " ;
    std::cin >> MyArray[3];
    std::cout << std::endl;

    std::cout << "Integer #5: " ;
    std::cin >> MyArray[4];
    std::cout << std::endl;


    std::cout << &MyArray[0] << std::endl;
    std::cout << &MyArray[1] << std::endl;
    std::cout << &MyArray[2] << std::endl;
    std::cout << &MyArray[3] << std::endl;
    std::cout << &MyArray[4] << std::endl;

    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array

    return 0;
}