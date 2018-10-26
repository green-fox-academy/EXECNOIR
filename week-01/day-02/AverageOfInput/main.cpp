#include <iostream>

int main(int argc, char* args[]) {
    int a;
    int b;
    int c;
    int d;
    int e;
    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    std::cin >> e;

    std::cout << "Sum: " << a+b+c+d+e << std::endl;
    std::cout << "Average: " << (a+b+c+d+e)/5 << std::endl;
    return 0;
}