
// Created by EXEC_NOIR on 11/13/2018.
//

#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H


class Animal {
public:
    Animal();
    int GetHunger();
    int GetThirst();
    void eat();
    void drink();
    void play();
private:
    int _hunger;
    int _thirst;
};


#endif //ANIMAL_ANIMAL_H
