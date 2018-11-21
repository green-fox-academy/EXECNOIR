//
// Created by EXEC_NOIR on 11/21/2018.
//

#include "Printer2D.h"

Printer2D::Printer2D(int sizeX, int sizeY) : _sizeX(sizeX), _sizeY(sizeY) {}

std::string Printer2D::getSize() {
    auto x = std::to_string(_sizeX);
    auto y = std::to_string(_sizeY);
    return x + " X " + y;
}
