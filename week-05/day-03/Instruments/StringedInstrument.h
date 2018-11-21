//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef INSTRUMENTS_STRINGEDINSTRUMENT_H
#define INSTRUMENTS_STRINGEDINSTRUMENT_H
#include "Instruments.h"
#include <iostream>

class StringedInstrument : public Instruments {
public:
    virtual std::string sound() = 0;
protected:
    int _numberOfStrings;
private:

};


#endif //INSTRUMENTS_STRINGEDINSTRUMENT_H
