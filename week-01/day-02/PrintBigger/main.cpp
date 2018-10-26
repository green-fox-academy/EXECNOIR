#include <iostream>

int main(int argc, char* args[]) {
    int a;
    int b;
    // Write a program that asks for two numbers and prints the bigger one
    std::cout << "Feed me two numbers!" << std::endl;
    std::cout << "First number" << std::endl;
    std::cin >> a;
    std::cout << "Second number" << std::endl;
    std::cin >> b;

    if(a>b){std::cout << "The first number is bigger!" << std::endl;};
    if(a<b){std::cout << "The second number is bigger!" << std::endl;};
    if(a==b){std::cout << "They are even!" << std::endl;};

    return 0;
}