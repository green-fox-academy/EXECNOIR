#include <iostream>

int main(int argc, char* args[]) {
    int x;
    int y;
    std::cout << "Please enter an integer:" << std::endl;
    std::cin >> x;
    std::cout << "Please enter another integer" << std::endl;
    std::cin >> y;

    if( x > y){
        std::cout << "The second numer should be bigger" << std::endl;
    }
    else{
        for (; x < y ;++x) {
            std::cout << x << std::endl;
        }

    }


    // Create a program that asks for two numbers
    // If the second number is not bigger than the first one it should print:
    // "The second number should be bigger"
    //
    // If it is bigger it should count from the first number to the second by one
    //
    // example:
    //
    // first number: 3, second number: 6, should print:
    //
    // 3
    // 4
    // 5

    return 0;
}