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


    for (int q = 0; q < sizeof(MyArray)/sizeof(MyArray[0]) ; ++q) {
        std::cout << *MyArray + q << std::endl;
    }
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array 
    // print out the values of that array using pointers again

    return 0;
}