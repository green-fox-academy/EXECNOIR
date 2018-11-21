//
// Created by EXEC_NOIR on 11/20/2018.
//

#ifndef GREENFOXINHERITANCE_COHORT_H
#define GREENFOXINHERITANCE_COHORT_H
#include <vector>
#include <iostream>
#include "Student.h"
#include "Mentor.h"


class Cohort {
public:
    Cohort(const std::string &name);

    void addStudent(Student* student) ;
    void addMentor(Mentor* mentor);
    void info();
protected:
private:
    std::string _name;
    std::vector<Student*> _students;
    std::vector<Mentor*> _mentors;
};


#endif //GREENFOXINHERITANCE_COHORT_H
