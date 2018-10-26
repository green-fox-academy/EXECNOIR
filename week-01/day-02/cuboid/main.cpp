#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000
    int side1 = 15;
    int side2 = 10;
    int side3 = 5;

    std::cout << "Surface Area: " << 2*(side1*side2+side2*side3+side3*side1) << std::endl;
    std::cout << "Volume: " << side1*side2*side3 << std::endl;


    return 0;
}