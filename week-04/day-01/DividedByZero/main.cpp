#include <iostream>
#include <fstream>


void divideten(float x);


int main() {
    float number;
    std::cout << "give me an integer!" << std::endl;
    std::cin >> number;
    divideten(number);

    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0

    return 0;
}

void divideten(float x) {
    try {

        if (x == 0) {
            throw "Can't divide by 0!";
        }
        x = 10 / x;
        std::cout << "10 divided by " << x << " is: " << 10/x << std::endl;
    } catch (char const *e) {
        std::cout << e << std::endl;
    }

}