//
// Created by EXEC_NOIR on 11/14/2018.
//

#include <iostream>
#include "Station.h"

Station::Station(int gasAmount) : _gasAmount(gasAmount) {

}
void Station::Fill(Car car) {
    while(car.isFull()!= true){
        car.fill();
        _gasAmount -= 1;
        std::cout << "Transferring 1 amount of gas to car." << std::endl;
    }
    std::cout << "Remaining gas in the station is: " << _gasAmount << std::endl;
}

int Station::getGasAmount() const {
    return _gasAmount;
}
