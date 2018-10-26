#include <iostream>

int main(int argc, char* args[]) {
    int chicken;
    int pig;
    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have
    std::cout << "How many chickens you have?" << std::endl;
    std::cin >> chicken;
    std::cout << "How many pigs you have?" << std::endl;
    std::cin >> pig;
    std::cout << "All your animals have " << pig*4+chicken*2 << " legs collectivelz.";
    return 0;
}