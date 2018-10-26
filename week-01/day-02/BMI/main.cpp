#include <iostream>

int main(int argc, char* args[]) {

    double massInKg = 81.2;
    double heightInM = 1.78;
    double heightInMsquared = heightInM*heightInM;



    // Print the Body mass index (BMI) based on these values
    std::cout << "The BMI is " << massInKg/heightInMsquared << std::endl;
    return 0;
}