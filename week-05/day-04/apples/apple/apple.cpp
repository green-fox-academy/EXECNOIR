//
// Created by EXEC_NOIR on 11/22/2018.
//
#include "apple.h"

std::string getApple(){
    return "apple";
}

int sumNum(){
    std::vector<int> num;
    for (int i = 1; i <= 5 ; ++i) {
        num.push_back(i);
    }
    int counter = 0;
    for (int j = 0; j < num.size() ; ++j) {
        counter = counter + num[j];
    }
    return counter;
}