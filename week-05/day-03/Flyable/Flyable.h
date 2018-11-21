//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef FLYABLE_FLYABLE_H
#define FLYABLE_FLYABLE_H

#include <iostream>

class Flyable {
public:
    virtual void fly() = 0;
    virtual void land() = 0;
    virtual void takeOff() = 0;
};


#endif //FLYABLE_FLYABLE_H
