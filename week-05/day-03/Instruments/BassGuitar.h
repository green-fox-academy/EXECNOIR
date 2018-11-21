//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef INSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTS_BASSGUITAR_H
#include "StringedInstrument.h"

class BassGuitar : public StringedInstrument{
public:
    BassGuitar();
    BassGuitar(int strings);

    std::string sound() override;
    void play() override;
protected:


};


#endif //INSTRUMENTS_BASSGUITAR_H
