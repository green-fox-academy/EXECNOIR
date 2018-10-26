#include <iostream>

int main(int argc, char* args[]) {
    int number;
    // Write a program that reads a number from the standard input,
    // Then prints "Odd" if the number is odd, or "Even" if it is even.
    std::cout << "Feed me a number!" << std::endl;
    std::cin >> number;
    if(number%2 == 0)
        {std::cout << "Even" << std::endl;} else{
            std::cout << "Odd" << std::endl;}
            ;
    return 0;
}