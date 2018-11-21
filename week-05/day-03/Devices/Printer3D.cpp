//
// Created by EXEC_NOIR on 11/21/2018.
//

#include "Printer3D.h"

Printer3D::Printer3D(int sizeX, int sizeY, int sizeZ) : _sizeX(sizeX), _sizeY(sizeY), _sizeZ(sizeZ) {}

std::string Printer3D::getSize() {
    auto x = std::to_string(_sizeX);
    auto y = std::to_string(_sizeY);
    auto z = std::to_string(_sizeZ);
    return x + " X " + y + " X " + z;
}
