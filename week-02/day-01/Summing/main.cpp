#include <iostream>
#include <string>

int sum(int x);

int main(int argc, char* args[]) {
    int number;
    // - Write a function called `sum` that sum all the numbers
    //Until the given parameter and returns with an integer
    std::cout << "Give me an integer!" << std::endl;
    std::cin >> number;
    std::cout << sum(number) << std::endl;
    return 0;
}

int sum(int x){
   int z = 0;
    for(int y = 1; y <= x;y++){
        z = z+y;
    };
return  z;
}