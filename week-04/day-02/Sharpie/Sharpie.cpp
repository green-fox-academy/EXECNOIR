//
// Created by EXEC_NOIR on 11/13/2018.
//

#include "Sharpie.h"

Sharpie::Sharpie(std::string color, int width) {
    _inkAmount = 100;
    _width = width;
    _color = color;
}

int Sharpie::GetWidth() {
    return _width;
}

int Sharpie::GetInkAmount() {
    return _inkAmount;
}

std::string Sharpie::GetColor() {
    return _color;
}

void Sharpie::use() {
    _inkAmount -= 1;
    std::cout << "Sharpie "<< _color << " was used" << std::endl;
}
