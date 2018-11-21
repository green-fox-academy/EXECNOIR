//
// Created by EXEC_NOIR on 11/20/2018.
//

#include "Mentor.h"

Mentor::Mentor(const std::string &name, int age, Gender gender, Level level) : Person(name, age, gender),
                                                                               _level(level) {}
Mentor::Mentor(){
    _name = "Jane Doe";
    _age = 30;
    _gender = Gender::FEMALE;
    _level = Level::INTERMEDIATE;
}

void Mentor::getGoal() {
    std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}

void Mentor::introduce() {
    std::cout << "Hi, I'm " << _name << " , a " << _age << " " << "year old " << getGender() << " "
    << getLevel() << " mentor." << std::endl;
}
std::string Mentor::getLevel(){
    if(_level == Level::JUNIOR){
        return "Junior";
    }else if(_level == Level::INTERMEDIATE){
        return "Intermediate";
    }else if(_level == Level::SENIOR){
        return "Senior";
    }
}

