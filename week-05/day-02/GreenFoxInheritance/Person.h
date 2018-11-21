//
// Created by EXEC_NOIR on 11/20/2018.
//

#ifndef GREENFOXINHERITANCE_PERSON_H
#define GREENFOXINHERITANCE_PERSON_H
#include <iostream>
enum class Gender {
    MALE,
    FEMALE
};

class Person {
public:
    Person(const std::string &name, int age, Gender gender);
    Person();
    virtual void getGoal();
    virtual void introduce();
    std::string getGender();
public:

protected:
    std::string _name;
    int _age;
    Gender _gender;
private:

};


#endif //GREENFOXINHERITANCE_PERSON_H
