//
// Created by EXEC_NOIR on 11/21/2018.
//

#include "Copier.h"

Copier::Copier(int sizeX, int sizeY, int speed) : Printer2D(sizeX, sizeY), Scanner(speed) {}

void Copier::copy() {
    scan();
    std::cout << " and ";
    print();

}
