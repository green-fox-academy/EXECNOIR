#include <iostream>
#include <string>

int main(int argc, char* args[]) {
    std::string animals[3] = {"koal", "pand", "zebr"};
    // - Create an array variable named `animals`
    //   with the following content: `["koal", "pand", "zebr"]`
    // - Add all elements an `"a"` at the end
    for(int x = 0; x<sizeof(animals)/sizeof(animals[0]);x++){

        animals[x] = animals[x] +="a";
        std::cout << animals[x] << std::endl;
    }
    return 0;
}