#include <iostream>


int main(int argc, char* args[]) {
    int x;
    std::cout << "Please enter an integer:" << std::endl;
    std::cin >> x;

    for (int i = 0; i <= x ; ++i) {

        for (int j = 0; j < i; ++j) {
            std::cout << "*" ;
        }
        std::cout<< "\n";
    }

    // Write a program that reads a number from the standard input, then draws a
    // triangle like this:
    //
    // *
    // **
    // ***
    // ****
    //
    // The triangle should have as many lines as the number was

    return 0;
}