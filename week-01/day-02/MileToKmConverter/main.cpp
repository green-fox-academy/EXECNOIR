#include <iostream>

int main(int argc, char* args[]) {
    int kilometer;
    std::cout << "This is a kilometer to mile converter" << std::endl;
    std::cin >> kilometer;
        // Write a program that asks for an integer that is a distance in kilometers,
        // then it converts that value to miles and prints it
        double mile = (double) kilometer / 100 * 62;
        std::cout << kilometer << " kilometers would be " << mile << " in miles.";
    return 0;
}