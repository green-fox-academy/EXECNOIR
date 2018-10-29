#include <iostream>
#include <string>

int main(int argc, char* args[]) {
    int p1[3] = {1, 2, 3};
    int p2[2] = {4, 5};
    // - Create an array variable named `p1`
    //   with the following content: `[1, 2, 3]`
    // - Create an array variable named `p2`
    //   with the following content: `[4, 5]`
    // - Print if `p2` has more elements than `p1`
    if(sizeof(p1) < sizeof(p2)){
        std::cout << "valami" << std::endl;
    }else{std::cout << "tomb 1 nagyobb" << std::endl;}
    return 0;
}