#include <iostream>


void switcheroo(int *a, int *b)

{
int c = *a;
*a = *b;
*b = c;
std::cout << "after swap" << std::endl;
std::cout << *a << " " <<*b << std::endl;
}



int main ()
{
    // Create a function which swaps the values of 'a' and 'b'
    // This time use a void funtion and pointers

    int a = 10;
    int b = 316;
    std::cout << "before swap" << std::endl;
    std::cout << a << " " << b << std::endl;
    switcheroo(&a, &b);
    return 0;
}