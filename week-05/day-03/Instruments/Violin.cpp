//
// Created by EXEC_NOIR on 11/21/2018.
//

#include "Violin.h"

Violin::Violin(){
    _name = "Violin";
    _numberOfStrings = 4;
};

std::string Violin::sound() {
    return "Screech";
}

void Violin::play() {
    std::cout << _name <<" a " << _numberOfStrings << "-stringed instrument that goes " << sound() << std::endl;
}

Violin::Violin(int strings){
    _numberOfStrings = strings;
    _name = "Screech";
}
