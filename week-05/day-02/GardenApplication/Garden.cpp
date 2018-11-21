//
// Created by EXEC_NOIR on 11/20/2018.
//

#include "Garden.h"

Garden::Garden() {
    _plants.clear();
}

void Garden::waterPlants(int waterAmount) {
    std::cout << "Watering with " << waterAmount << std::endl;
    int counter = 0;
    for (int i = 0; i < _plants.size() ; ++i) {
        if( _plants[i]->getState()){
            counter ++;
        }
    }
    for (int j = 0; j < _plants.size(); ++j) {
        if(_plants[j]->getState()) {
            _plants[j]->waterPlants(waterAmount / counter);
        }
    }
}

void Garden::getStateAll() {
    for (int i = 0; i < _plants.size() ; ++i) {
        if(_plants[i]->getState()){
            std::cout << "The " << _plants[i]->getColor() << " " <<_plants[i]->getName() << " needs water."
            << std::endl;
        }else{
            std::cout << "The " << _plants[i]->getColor() << " " <<_plants[i]->getName() << " doesn't need water."
                      << std::endl;
        }
    }
}
void Garden::push_back(Flower* flower) {
    _plants.push_back(flower);
}