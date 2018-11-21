//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef ANIMALSINTHEZOO_ANIMAL_H
#define ANIMALSINTHEZOO_ANIMAL_H

#include <iostream>

class Animal {
public:
    virtual std::string getName() = 0;
    virtual std::string breed() = 0;
protected:
    int _age;
    std::string _name;
private:
};


#endif //ANIMALSINTHEZOO_ANIMAL_H
