//
// Created by EXEC_NOIR on 11/21/2018.
//

#include "Bird.h"

Bird::Bird(std::string name) {
    _name = name;
}

std::string Bird::getName() {
    return _name;
}

void Bird::fly() {
    std::cout << "The bird "<< getName() << " flies" << std::endl;
}

void Bird::land() {
    std::cout << "The bird " << getName() << " lands" << std::endl;
}

void Bird::takeOff() {
    std::cout << "The bird " << getName() << " takes off" << std::endl;
}

