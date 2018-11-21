//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef DEVICES_COPIER_H
#define DEVICES_COPIER_H

#include "Scanner.h"
#include "Printer2D.h"

class Copier : public Printer2D, public Scanner {
public:
    Copier(int sizeX, int sizeY, int speed);
    void copy();
};


#endif //DEVICES_COPIER_H
