//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef INSTRUMENTS_VIOLIN_H
#define INSTRUMENTS_VIOLIN_H
#include "StringedInstrument.h"

class Violin : public StringedInstrument{
public:
    Violin();
    Violin(int strings);

    std::string sound() override;
    void play() override;
protected:

};


#endif //INSTRUMENTS_VIOLIN_H
