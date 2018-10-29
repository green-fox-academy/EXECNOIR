#include <iostream>
#include <string>

void appendAFunc (std::string x);

int main(int argc, char* args[]) {
    std::string typo = "Chinchill" ;
    // - Create a string variable named `typo` and assign the value `Chinchill` to it
    // - Write a function called `appendAFunc` that gets a string as an input,
    //   appends an 'a' character to its end and returns with a string
    //
    // - Print the result of `appendAFunc(typo)`
    appendAFunc(typo);

    return 0;
}

void appendAFunc(std::string x){

    std::cout << x << "a" << std::endl;
}