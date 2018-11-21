//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef DEVICES_PRINTER3D_H
#define DEVICES_PRINTER3D_H
#include "Printer.h"

class Printer3D : public Printer {
public:
    Printer3D(int sizeX, int sizeY, int sizeZ);
    std::string getSize() override;
public:
protected:
private:
    int _sizeX;
    int _sizeY;
    int _sizeZ;
};


#endif //DEVICES_PRINTER3D_H
