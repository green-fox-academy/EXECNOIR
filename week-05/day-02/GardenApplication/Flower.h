//
// Created by EXEC_NOIR on 11/20/2018.
//

#ifndef GARDENAPPLICATION_FLOWER_H
#define GARDENAPPLICATION_FLOWER_H
#include <iostream>



enum class Color {
    YELLOW,
    BLUE,
    PURPLE,
    ORANGE
};


class Flower {
public:
    Flower(Color color);
    virtual void waterPlants(int waterAmount);
    virtual bool getState();
    std::string getColor();
    virtual std::string getName();
protected:
    Color _color;
    int _waterAmount;

private:

};


#endif //GARDENAPPLICATION_FLOWER_H
