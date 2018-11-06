#include <iostream>

int main()
{
    int maxi = 0;
    int size;
    std::cout << "Array size (int): " << std::endl;
    std::cin >> size;
    int MyArray[size];


    for (int i = 0; i < size; ++i) {

        std::cout << "Number at index " << i << " :" << std::endl;
        std::cin >> MyArray[i];

    }
    for (int j = 0; j < size ; ++j) {

        if(MyArray[j] > maxi){

            maxi = MyArray[j];
        }

    }
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it
    std::cout << "The maximum of the array is: " << maxi << std::endl;
    return 0;
}