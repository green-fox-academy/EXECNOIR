//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef DEVICES_PRINTER_H
#define DEVICES_PRINTER_H
#include <iostream>

class Printer {
public:
    virtual std::string getSize() = 0;
    void print();

};


#endif //DEVICES_PRINTER_H
