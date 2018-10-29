#include <iostream>
#include <string>

int main(int argc, char* args[]) {
    int numList[5] = {3, 4, 5, 6, 7};
    // - Create an array variable named `numList`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Double all the values in the array
    for (int x=0; x < sizeof(numList)/sizeof(numList[5]);x++){
        numList[x] = numList[x]*2;
        std::cout << numList[x] << std::endl;
    };
    return 0;
}