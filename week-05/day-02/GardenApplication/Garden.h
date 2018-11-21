//
// Created by EXEC_NOIR on 11/20/2018.
//

#ifndef GARDENAPPLICATION_GARDEN_H
#define GARDENAPPLICATION_GARDEN_H
#include <iostream>
#include <vector>
#include "Flower.h"
class Garden {
public:
    Garden();
    void push_back(Flower* flower);
    void getStateAll();
    void waterPlants(int waterAmount);
protected:
private:
    std::vector<Flower*> _plants;
};


#endif //GARDENAPPLICATION_GARDEN_H
