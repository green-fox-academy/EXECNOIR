#include <iostream>
#include "Sharpie.h"

int main() {
    Sharpie red("red", 5);
    std::cout << "Sharpie color: " << red.GetColor() << std::endl <<
    "Sharpie width: " << red.GetWidth() << std::endl;
    std::cout << "remaining ink:" << red.GetInkAmount() << std::endl;
    red.use();
    std::cout << "remaining ink: " << red.GetInkAmount() << std::endl;
    return 0;
}