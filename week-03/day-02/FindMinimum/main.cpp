#include <iostream>
int *FindMinimum(int *Array, int length);
int main()
{
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 5, 15};
    std::cout << *FindMinimum(numbers, sizeof(numbers)/sizeof(numbers[0])) << std::endl;

    return 0;
}

int *FindMinimum(int *Array, int length){
    int mini = Array[0];
    int *miniMemory;
    for (int i = 0; i < length; ++i) {
        if(Array[i] < mini){
            mini = Array[i];
            miniMemory = &Array[i];
        }
    }
    return miniMemory;
}