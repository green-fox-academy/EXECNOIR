#include <iostream>

// Given base and n that are both 1 or more, compute recursively (no loops)
// the value of base to the n power, so powerN(3, 2) is 9 (3 squared).

int purePower(int base, int n);

int main() {
    std::cout << purePower(3, 4) << std::endl;
    return 0;
}

int purePower(int base, int n){

    if(base <= 0 || n <= 1){
        return base;
    }else{

        return base*purePower(base, n-1);
    }


}