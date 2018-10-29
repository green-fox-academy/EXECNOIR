#include <iostream>
#include <string>

int factorio(int x);

int main(int argc, char* args[]) {
    int number;
    // - Create a function called `factorio`
    //   that returns it's input's factorial
    std::cout << "Give me an integer" << std::endl;
    std::cin >> number;
    std::cout << factorio(number) << std::endl;
    return 0;
}

int factorio(int x){
    int y = x-1;
    for(; y>0; y--){
        x = x*y;


    }
return x;
}