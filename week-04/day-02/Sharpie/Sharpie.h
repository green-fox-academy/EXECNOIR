//
// Created by EXEC_NOIR on 11/13/2018.
//

#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H

#include <iostream>

class Sharpie {
public:
    Sharpie(std::string color, int width);
    int GetWidth();
    int GetInkAmount();
    std::string GetColor();
    void use();
private:
    int _inkAmount;
    int _width;
    std::string _color;
};


#endif //SHARPIE_SHARPIE_H
