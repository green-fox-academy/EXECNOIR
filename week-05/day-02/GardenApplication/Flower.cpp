//
// Created by EXEC_NOIR on 11/20/2018.
//

#include "Flower.h"

Flower::Flower(Color color) : _color(color) {
    _waterAmount = 0;
}

bool Flower::getState() {
    if(_waterAmount > 5){
        return false;
    }else{
        return true;
    }
}
std::string Flower::getColor(){
    if( _color == Color::BLUE){
        return "Blue";
    }else if( _color == Color::ORANGE){
        return "Orange";
    }else if( _color == Color::PURPLE){
        return "Purple";
    }else if( _color == Color::YELLOW){
        return "Yellow";
    }
}
std::string Flower::getName(){
    return "Flower";
}

void Flower::waterPlants(int waterAmount) {
    _waterAmount = _waterAmount + (waterAmount*0.75);
}

