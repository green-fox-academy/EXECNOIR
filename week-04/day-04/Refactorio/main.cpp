#include <iostream>

// Create a recursive function called `refactorio`
// that returns it's input's factorial
int factorial(int x);

int main() {
    std::cout << factorial(31) << std::endl;
    return 0;
}

int factorial(int x){
    if(x <= 1){
        return x;
    }else{
        return x*factorial(x-1);
    }
}