//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef ANIMALSINTHEZOO_REPTILE_H
#define ANIMALSINTHEZOO_REPTILE_H


#include "LaysEggs.h"

class Reptile : public LaysEggs {
public:
    Reptile(std::string name);

    std::string getName() override;



};


#endif //ANIMALSINTHEZOO_REPTILE_H
