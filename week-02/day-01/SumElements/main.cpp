#include <iostream>
#include <string>

int main(int argc, char* args[]) {
    int r[4] = {54, 23, 66, 12};
    // - Create an array variable named `r`
    //   with the following content: `[54, 23, 66, 12]`
    // - Print the sum of the second and the third element
    std::cout << r[1] + r[2] << std::endl;
    return 0;
}