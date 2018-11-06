#include <iostream>
#include <algorithm>



int TakesAnArrayAndANumberAsItsParameter(int *Array, int ArrayLenght, int number) {

    for (int i = 0; i < ArrayLenght; ++i) {
        if (Array[i] == number) {
            return i;
        }
    }
        return 0;

        }


int main()
{

    int MyArray[4] = {1,3,4,5};

    std::cout << TakesAnArrayAndANumberAsItsParameter(MyArray, sizeof(MyArray)/sizeof(MyArray[0]), 3) << std::endl;
    std::cout << sizeof(MyArray)/sizeof(MyArray[0]) << std::endl;




    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return 0

    return 0;
}