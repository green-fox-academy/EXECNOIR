//
// Created by EXEC_NOIR on 11/21/2018.
//
#include "Helicopter.h"

Helicopter::Helicopter(int speed, int weight, Color color) {
    _maxspeed = speed;
    _weight = weight;
    _color = color;
}

void Helicopter::fly() {
    std::cout << "The " << getColor() << " helicopter flies with " << _maxspeed << " km/h speed." << std::endl;
}

void Helicopter::land() {
    std::cout << "The " << getColor() << " helicopter just landed." << std::endl;
}

void Helicopter::takeOff() {
    std::cout << "The " << getColor() << " helicopter took off with " << _weight << " kg." << std::endl;
}
