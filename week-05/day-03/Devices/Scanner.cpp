//
// Created by EXEC_NOIR on 11/21/2018.
//

#include "Scanner.h"

Scanner::Scanner(int speed) : _speed(speed) {}

void Scanner::scan() {
    std::cout << "I'm scanning a document " << _speed << " ppm";
}
