#include <iostream>

// We have bunnies standing in a line, numbered 1, 2, ... The odd bunnies
// (1, 3, ..) have the normal 2 ears. The even bunnies (2, 4, ..) we'll say
// have 3 ears, because they each have a raised foot. Recursively return the
// number of "ears" in the bunny line 1, 2, ... n (without loops or multiplication).
int fulek(int x);

int main() {
    std::cout << fulek(131) << std::endl;
    return 0;
}

int fulek(int x){

    if( x <= 0){
        return x;
    }else if(x%2 == 0){
        return fulek(x-1) + 3;
    }else
        {
        return fulek(x-1) + 2;
        }


}