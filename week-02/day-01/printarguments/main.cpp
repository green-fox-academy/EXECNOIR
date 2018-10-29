#include <iostream>
#include <string>

void printParams(std::string text1);
void printParams(std::string text1, std::string text2);
void printParams(std::string text1, std::string text2, std::string text3);

int main(int argc, char* args[]) {

    // - Create a function called `printParams`
    //   which prints the input String parameters
    // - It can have any number of parameters
    std::string input1 = "";
    std::string input2 = "";
    // Examples
    // printParams("first")
    // printParams("first", "second")
    // printParams("first", "second", "third", "fourh")
    // ...
    std::cout << "Line of string please!" << std::endl;
    std::cin >> input1;
    std::cout << "Thanks! Now another one please!" << std::endl;
    std::cin >> input2;
    printParams(input1, input2);
    return 0;
}

void printParams(std::string text1, std::string text2){
    std::cout << text1 << text2 << std::endl;
}

void printParams(std::string text1, std::string text2, std::string text3){

    std::cout << text1 << text2 << text3 << std::endl;
}

void printParams(std::string text1){

    std::cout << text1 << std::endl;
}