//
// Created by EXEC_NOIR on 11/14/2018.
//

#ifndef PETROL_STATION_H
#define PETROL_STATION_H

#include <iostream>
#include "Car.h"

class Station {
public:
    Station(int gasAmount);
    void Fill(Car);

    int getGasAmount() const;

public:


private:
    int _gasAmount;
};



#endif //PETROL_STATION_H
