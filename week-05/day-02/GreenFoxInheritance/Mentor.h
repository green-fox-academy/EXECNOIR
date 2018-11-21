//
// Created by EXEC_NOIR on 11/20/2018.
//

#ifndef GREENFOXINHERITANCE_MENTOR_H
#define GREENFOXINHERITANCE_MENTOR_H

#include "Person.h"

enum class Level{
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};

class Mentor : public Person {
public:
    std::string getLevel();
    Mentor(const std::string &name, int age, Gender gender, Level level);
    Mentor();
    void getGoal() override;
    void introduce() override;
protected:
private:
    Level _level;

};


#endif //GREENFOXINHERITANCE_MENTOR_H
