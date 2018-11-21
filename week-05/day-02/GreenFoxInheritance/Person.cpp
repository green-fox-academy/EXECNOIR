//
// Created by EXEC_NOIR on 11/20/2018.
//

#include "Person.h"

Person::Person(const std::string &name, int age, Gender gender) : _name(name), _age(age), _gender(gender) {};

Person::Person(){
    _name = "Jane Doe";
    _age = 30;
    _gender = Gender::FEMALE;
}

void Person::getGoal() {

    std::cout << "My goal is: Live for the moment!" << std::endl;
}

void Person::introduce() {

    std::cout << "Hi, I'm " << _name << " , a " << _age << " year old " << getGender() << std::endl;
}

std::string Person::getGender(){
    if( _gender == Gender::FEMALE){
        return "Female";
    }else if( _gender == Gender::MALE){
        return "Male";
    }
}
