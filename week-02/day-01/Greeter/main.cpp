#include <iostream>
#include <string>

void greet(std::string x);

int main(int argc, char* args[]) {
    std::string al = "Greenfox";
    // - Create a string variable named `al` and assign the value `Greenfox` to it
    // - Create a function called `greet` that greets it's input parameter
    // - Greeting is printing e.g. `Greetings dear, Greenfox`
    // - Greet `al`
    greet(al);
    return 0;
}

void greet(std::string x){
    std::cout << "Greetings dear, " << x << std::endl;
}