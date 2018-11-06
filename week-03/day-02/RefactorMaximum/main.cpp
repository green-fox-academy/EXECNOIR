#include <iostream>

int size();

void elements(int *Array, int ArrayLength);

int FindMaxi(int *Array, int Length);

int main() {

    int MyArray[size()];
    elements(MyArray, sizeof(MyArray) / sizeof(MyArray[0]));
    std::cout << "The maximum of the array is: " << FindMaxi(MyArray, sizeof(MyArray)/sizeof(MyArray[0])) << std::endl;
    return 0;
}

int FindMaxi(int *Array, int Length)
{
    int maxi = Array[0];
    for (int j = 0;j<Length;++j) {

        if (Array[j] > maxi){

            maxi = Array[j];
        }

    }
    return maxi;
}

void elements(int *Array, int ArrayLength) {

    for (int i = 0; i < ArrayLength; ++i) {

        std::cout << "Number at index " << i << " :" << std::endl;
        std::cin >> *(Array + i);

    }

}

int size() {

    int size;
    std::cout << "Array size (int): " << std::endl;
    std::cin >> size;


    return size;
}