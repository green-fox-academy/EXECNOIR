//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef FLYABLE_HELICOPTER_H
#define FLYABLE_HELICOPTER_H

#include "Vehicle.h"
#include "Flyable.h"

class Helicopter : public Vehicle, public Flyable {
public:
    Helicopter(int speed, int weight, Color color);

    void fly() override;

    void land() override;

    void takeOff() override;
};


#endif //FLYABLE_HELICOPTER_H
