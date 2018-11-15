#include <iostream>

int numberAdder(int x);

int main() {
    std::cout << numberAdder(5) << std::endl;
    return 0;
}

int numberAdder(int x){
    if(x <=1){
        return 1;
    }else{
        return x+numberAdder(x-1);
    }



}