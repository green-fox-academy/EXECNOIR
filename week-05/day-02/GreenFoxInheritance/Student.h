//
// Created by EXEC_NOIR on 11/20/2018.
//

#ifndef GREENFOXINHERITANCE_STUDENT_H
#define GREENFOXINHERITANCE_STUDENT_H
#include "Person.h"

class Student : public Person{
public:
    Student();

    Student(const std::string &name, int age, Gender gender, const std::string &previousOrganization);
    int skipDays(int numberOfDays);
    void getGoal() override;
    void introduce() override;
private:
    std::string _previousOrganization;
    int _skippedDays;
};


#endif //GREENFOXINHERITANCE_STUDENT_H
