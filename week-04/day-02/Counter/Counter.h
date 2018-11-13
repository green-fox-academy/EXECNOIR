//
// Created by EXEC_NOIR on 11/13/2018.
//

#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class Counter {
public:
    Counter();
    Counter(int number);
    void add(int number);
    void add();
    int get();
    void reset();
private:
    int _number;
    int _initial;

};


#endif //COUNTER_COUNTER_H
