#include <iostream>
#include <string>

int main(int argc, char* args[]) {
    int aj[5] = {3, 4, 5, 6, 7};
    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`
    int placeholder;

    for(int x = 0; x < sizeof(aj)/sizeof(aj[0])/2; x++){

        placeholder = aj[x];
        aj[x] = aj[sizeof(aj)/sizeof(aj[0])]-sizeof(aj[x]);
        int placeholder2 = aj[sizeof(aj)/sizeof(aj[0])]-sizeof(aj[x]);
        placeholder2 + placeholder;
        std::cout << aj[x] << std::endl;
    }


    return 0;
}