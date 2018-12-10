//
// Created by EXEC_NOIR on 12/10/2018.
//

#include "Cards.h"

Cards::Cards(Value value, Suite suite) : _suite(suite), _value(value) {}

Value Cards::getValue() const {
    return _value;
}