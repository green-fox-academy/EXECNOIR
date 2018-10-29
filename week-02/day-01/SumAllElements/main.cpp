#include <iostream>
#include <string>

int main(int argc, char* args[]) {
    int ai[5] = {3, 4, 5, 6, 7};
    // - Create an array variable named `ai`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Print the sum of the elements in `ai`
    int z = 0;
    for(int x=0; x < sizeof(ai)/sizeof(ai[0]);x++){

        z = z+ai[x];
    }
    std::cout << z << std::endl;
    return 0;
}