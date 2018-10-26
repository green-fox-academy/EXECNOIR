#include <iostream>

int main(int argc, char* args[]) {

    // Define several things as a variable then print their values
    // Your name as a string
    // Your age as an integer
    // Your height in meters as a double
    // Whether you are married or not as a boolean
    std::string name = "Gabor";
    int age = 28;
    double height = 181;
    bool married = false;
    std::cout << age << std::endl;
    std::cout << height << std::endl;
    if(married == false) {
        std::cout << "not married" << std::endl;
    };
    if(married == true) {
        std::cout << "married" << std::endl;
    };
    return 0;
}