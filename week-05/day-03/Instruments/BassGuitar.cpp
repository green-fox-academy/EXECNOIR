//
// Created by EXEC_NOIR on 11/21/2018.
//

#include "BassGuitar.h"

BassGuitar::BassGuitar(){
    _name = "Bass Guitar";
    _numberOfStrings = 4;
};

std::string BassGuitar::sound() {
    return "Duum-duum-duum";
}

void BassGuitar::play() {
    std::cout <<  _name <<" a " << _numberOfStrings << "-stringed instrument that goes " << sound() << std::endl;
}

BassGuitar::BassGuitar(int strings){
    _numberOfStrings = strings;
    _name = "Duum-duum-duum";
}