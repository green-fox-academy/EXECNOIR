//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef ANIMALSINTHEZOO_MAMMAL_H
#define ANIMALSINTHEZOO_MAMMAL_H
#include "Animal.h"

class Mammal : public Animal{
public:
    std::string getName() override;

    std::string breed() override;

    Mammal(std::string name);

protected:
private:
};


#endif //ANIMALSINTHEZOO_MAMMAL_H
