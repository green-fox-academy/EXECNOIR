//
// Created by EXEC_NOIR on 11/20/2018.
//

#ifndef GARDENAPPLICATION_TREE_H
#define GARDENAPPLICATION_TREE_H


#include "Flower.h"

class Tree : public Flower{
public:
    Tree(Color color);
    std::string getName() override;
    bool getState() override;
    void waterPlants(int waterAmount) override;
protected:
private:

};


#endif //GARDENAPPLICATION_TREE_H
