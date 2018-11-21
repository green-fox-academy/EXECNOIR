//
// Created by EXEC_NOIR on 11/21/2018.
//

#include "ElectricGuitar.h"

ElectricGuitar::ElectricGuitar(){
    _name = "Electric Guitar";
    _numberOfStrings = 6;
};

std::string ElectricGuitar::sound() {
    return "Twang";
}

void ElectricGuitar::play() {
    std::cout << _name << ", a " << _numberOfStrings << "-stringed instrument that goes " << sound() << std::endl;
}

ElectricGuitar::ElectricGuitar(int strings) {
    _numberOfStrings = strings;
    _name = "Electric Guitar";

}
