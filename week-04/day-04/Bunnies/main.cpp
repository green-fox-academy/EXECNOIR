#include <iostream>

// We have a number of bunnies and each bunny has two big floppy ears.
// We want to compute the total number of ears across all the bunnies recursively (without loops or multiplication).
int fulek(int x);

int main() {
    std::cout << fulek(20) << std::endl;
    return 0;
}

int fulek(int x){

    if( x <= 0){
        return x;
    }else{
        return fulek(x-1) + 2;
    }

}