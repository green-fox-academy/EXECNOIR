//
// Created by EXEC_NOIR on 11/14/2018.
//

#ifndef PETROL_CAR_H
#define PETROL_CAR_H
#include <iostream>



class Car {
public:
    Car(int gasAmount, int capacity);
    bool isFull();
    void fill();

public:
private:
    int _gasAmount;
    int _capacity;
};


#endif //PETROL_CAR_H
