//
// Created by EXEC_NOIR on 11/21/2018.
//

#ifndef DEVICES_SCANNER_H
#define DEVICES_SCANNER_H
#include <iostream>

class Scanner {
public:
    Scanner(int speed);
    void scan();
protected:
private:
    int _speed;
};


#endif //DEVICES_SCANNER_H
