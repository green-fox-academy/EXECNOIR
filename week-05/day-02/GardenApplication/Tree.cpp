//
// Created by EXEC_NOIR on 11/20/2018.
//

#include "Tree.h"


Tree::Tree(Color color) : Flower(color) {

    _waterAmount = 0;
}

bool Tree::getState() {
    if(_waterAmount > 10){
        return false;
    }else{
        return true;
    }
}

std::string Tree::getName() {
    return "Tree";
}

void Tree::waterPlants(int waterAmount) {
    _waterAmount = _waterAmount + (waterAmount*0.40);
}
