#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for a number.
    // It would ask this many times to enter an integer,
    // if all the integers are entered, it should print the sum and average of these
    // integers like:
    //
    // Sum: 22, Average: 4.4
    int x;
    int y;
    std::cout << "How many numbers are we working with?(integer):" << std::endl;
    std::cin >> x;
    int numbers[x];
    for (int i = 0; i < x; ++i) {

        std::cout << "Please, enter a number(integer):" << std::endl;
        std::cin >> y;
        numbers[i] = y;

    }
    int z = 0;
    for (int j = 0; j < x; ++j) {

        z = z + numbers[j];
    }
    std::cout << "Sum:" << z << std::endl;
    std::cout << "Average:" << z/x << std::endl;


    return 0;
}