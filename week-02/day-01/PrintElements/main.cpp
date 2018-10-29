#include <iostream>
#include <string>

int main(int argc, char* args[]) {
    int numbers[4] = {4, 5, 6, 7};
    // - Create an array variable named `numbers`
    //   with the following content: `[4, 5, 6, 7]`
    // - Print all the elements of `numbers`

    for(int x = 0; x <sizeof(numbers)/sizeof(numbers[0]); x++){

        std::cout << numbers[x] << std::endl;
    }
    return 0;
}