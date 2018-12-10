//
// Created by EXEC_NOIR on 12/10/2018.
//
#include <iostream>

#ifndef POKER_CARDS_H
#define POKER_CARDS_H

enum class Suite
{
    HEART,
    DIAMOND,
    SPADE,
    CLUB
};

enum class Value
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};



class Cards {
public:
    Cards(Value value, Suite suite);

    Value getValue() const;

private:
    Suite _suite;
    Value _value;


};

#endif //POKER_CARDS_H
