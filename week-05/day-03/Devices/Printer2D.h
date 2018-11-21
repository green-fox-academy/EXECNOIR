//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef DEVICES_PRINTER2D_H
#define DEVICES_PRINTER2D_H

#include "Printer.h"

class Printer2D : public Printer {
public:
    Printer2D(int sizeX, int sizeY);

    std::string getSize() override;

protected:
private:
    int _sizeX;
    int _sizeY;
};


#endif //DEVICES_PRINTER2D_H
