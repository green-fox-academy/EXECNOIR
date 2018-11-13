//
// Created by EXEC_NOIR on 11/13/2018.
//

#include "Animal.h"

Animal::Animal() {

    _hunger = 50;
    _thirst = 50;

}

int Animal::GetHunger() {
    return _hunger;
}

int Animal::GetThirst() {
    return _thirst;
}

void Animal::eat() {
    _hunger -= 1;
}

void Animal::drink() {
    _thirst -= 1;
}

void Animal::play() {
    _hunger += 1;
    _thirst += 1;
}
