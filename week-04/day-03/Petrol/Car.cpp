//
// Created by EXEC_NOIR on 11/14/2018.
//

#include <iostream>
#include "Car.h"
#include "Station.h"

Car::Car(int gasAmount, int capacity) : _gasAmount(gasAmount), _capacity(capacity) {

}
bool Car::isFull(){
    if(_gasAmount >= _capacity){
        return true;
    }
    if(_gasAmount < _capacity){
    return false;
    }

}
void Car::fill(){
    _gasAmount ++;
}