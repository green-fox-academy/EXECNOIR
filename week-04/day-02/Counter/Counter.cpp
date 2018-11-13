//
// Created by EXEC_NOIR on 11/13/2018.
//

#include "Counter.h"

Counter::Counter() {

    _number = 0;
    _initial = 0;
}

void Counter::add(int number) {
        _number = _number + number;


}

void Counter::add() {
    _number ++;
}

int Counter::get() {
    return _number;
}

void Counter::reset() {
    _number = _initial;

}

Counter::Counter(int number) {

    _number = number;
    _initial = number;
}
