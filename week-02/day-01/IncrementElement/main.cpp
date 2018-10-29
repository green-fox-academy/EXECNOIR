#include <iostream>
#include <string>

int main(int argc, char* args[]) {
    int t[5] = {1, 2, 3, 4, 5};
    // - Create an array variable named `t`
    //    with the following content: `[1, 2, 3, 4, 5]`
    // - Increment the third element
    // - Print the third element
    t[2] = t[2]+1;
    std::cout << t[2] << std::endl;
    return 0;
}