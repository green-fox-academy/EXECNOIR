#include <iostream>

int main ()
{
    // Change the value of the variable called 'temperature' using a pointer
    // (you have to create the pointer first)

    float temperature = 21.3;
    float *temperatureMemory = &temperature;

    *temperatureMemory += 2;

    std::cout << *temperatureMemory << std::endl;
    return 0;
}