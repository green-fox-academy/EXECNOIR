//
// Created by EXEC_NOIR on 11/21/2018.
//

#include "Mammal.h"

Mammal::Mammal(std::string name) {
    _name = name;
}

std::string Mammal::getName() {
    return _name;
}

std::string Mammal::breed() {
    return "pushing miniature versions out.";
}
