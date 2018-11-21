//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef INSTRUMENTS_ELECTRICGUITAR_H
#define INSTRUMENTS_ELECTRICGUITAR_H
#include "StringedInstrument.h"

class ElectricGuitar : public StringedInstrument{
public:
    ElectricGuitar();
    ElectricGuitar(int strings);

    std::string sound() override;
    void play() override;
protected:



};


#endif //INSTRUMENTS_ELECTRICGUITAR_H
