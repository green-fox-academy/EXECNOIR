//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef INSTRUMENTS_INSTRUMENTS_H
#define INSTRUMENTS_INSTRUMENTS_H
#include <iostream>

class Instruments {
public:
protected:
    virtual void play() = 0;
    std::string _name;
private:

};


#endif //INSTRUMENTS_INSTRUMENTS_H
