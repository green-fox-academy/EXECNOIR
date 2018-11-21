//
// Created by EXEC_NOIR on 11/21/2018.
//

#include "Vehicle.h"

int Vehicle::getSpeed() {
    return _maxspeed;
}

int Vehicle::getWeight() {
    return _weight;
}

std::string Vehicle::getColor() {
    if(_color == Color::RED){
        return "Red";
    }else if(_color == Color::BLUE){
        return "Blue";
    }else if(_color == Color::GREEN){
        return "Green";
    }
}
