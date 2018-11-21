//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef FLYABLE_VEHICLE_H
#define FLYABLE_VEHICLE_H
#include <iostream>
enum class Color{
    RED,
    BLUE,
    GREEN
};

class Vehicle {
public:
    int getSpeed();
    int getWeight();
    std::string getColor();
protected:
    int _maxspeed;
    int _weight;
    Color _color;
};


#endif //FLYABLE_VEHICLE_H
