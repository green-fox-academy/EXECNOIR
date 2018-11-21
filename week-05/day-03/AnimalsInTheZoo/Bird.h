//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef ANIMALSINTHEZOO_BIRD_H
#define ANIMALSINTHEZOO_BIRD_H
#include "LaysEggs.h"

class Bird : public LaysEggs{
public:
    Bird(std::string name);

    std::string getName() override;



};


#endif //ANIMALSINTHEZOO_BIRD_H
