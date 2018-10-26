#include <iostream>

int main(int argc, char* args[]) {

    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long
    //
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.
    //
    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52
    float codinghours = 17*5*6;
    float averagehours = 17*52;
    std::cout << "We spend " << codinghours << " hours coding this semester." << std::endl;

    float percentage = codinghours/averagehours*100;
    std::cout << "That's " << percentage << " of the average working hours spent coding." << std::endl;
    return 0;
}