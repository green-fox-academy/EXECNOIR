//
// Created by EXEC_NOIR on 11/20/2018.
//

#ifndef GREENFOXINHERITANCE_SPONSOR_H
#define GREENFOXINHERITANCE_SPONSOR_H


#include "Person.h"

class Sponsor : public Person{
public:
    Sponsor(const std::string &name, int age, Gender gender, const std::string &company);
    Sponsor();
    void hire();
    void introduce() override;
    void getGoal() override;

protected:
private:
    std::string _company;
    int _hiredStudents;
};


#endif //GREENFOXINHERITANCE_SPONSOR_H
