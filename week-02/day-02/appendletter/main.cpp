#include <iostream>
#include <string>
#include <vector>



std::vector<std::string> appendA(std::vector<std::string> animal){
    int x = 0;
    for(int z = 0; z < animal.size(); z++){
        animal[x] = animal[x] + "a";
        x = x+1;
    }
return animal;
}


int main(int argc, char* args[])
{
    std::vector<std::string> animals = {"bo", "anacond", "koal", "pand", "zebr"};

    // Create a function called "appendA()" that adds "a" to every string in the "animals" list.
    // The parameter should be a vector.

    for(const auto& animal : appendA(animals))
    {
        std::cout << animal << " ";
    }

    return 0;
}