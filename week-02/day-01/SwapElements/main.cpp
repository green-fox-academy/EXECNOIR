#include <iostream>
#include <string>

int main(int argc, char* args[]) {
    std::string abc[3] = {"first", "second", "third"};
    // - Create an array variable named `abc`
    //   with the following content: `["first", "second", "third"]`
    // - Swap the first and the third element of `abc`
    std::string placeholder = abc[0];
    abc[0] = abc[2];
    abc[2] = placeholder;
    std::cout << "first element " << abc[0] << std::endl;
    std::cout << "third elemenet " << abc[2] << std::endl;
    return 0;
}