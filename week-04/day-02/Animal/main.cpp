#include <iostream>
#include "Animal.h"

int main() {
    Animal szalamandra;

    std::cout << "hunger : " << szalamandra.GetHunger() << std::endl <<
    "thirst : " << szalamandra.GetThirst() << std::endl;

    szalamandra.eat();
    std::cout << "after eating: " << szalamandra.GetHunger() << std::endl;
    szalamandra.drink();
    std::cout << "after drinking: " << szalamandra.GetThirst() << std::endl;
    szalamandra.play();
    std::cout << "after playing: " << szalamandra.GetThirst() << std::endl <<
    szalamandra.GetHunger() << std::endl;

    return 0;
}