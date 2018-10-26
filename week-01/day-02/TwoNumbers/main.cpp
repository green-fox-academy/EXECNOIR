#include <iostream>

int main(int argc, char* args[]) {
    int number1 = 22;
    float number2 = 13;
    // Create a program that prints a few operations on two numbers: 22 and 13

    // Print the result of 13 added to 22
    std::cout << number1+number2 << std::endl;
    // Print the result of 13 substracted from 22
    std::cout << number1-number2 << std::endl;
    // Print the result of 22 multiplied by 13
    std::cout << number1*number2 << std::endl;
    // Print the result of 22 divided by 13 (as a decimal fraction)
    float divide = number1/number2;
    std::cout << divide << std::endl;
    // Print the integer part of 22 divided by 13
    int number2v2 = 13;
    std::cout << number1/number2v2 << std::endl;
    // Print the reminder of 22 divided by 13
    int remainder = number1 % number2v2;
    std::cout << remainder << std::endl;
    return 0;
}