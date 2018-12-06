#include <stdio.h>
#include <stdlib.h>

int oddOrEven(int x);

int main()
{
    int number;
    printf("Gibe number: \n");
    scanf("%d", &number);

    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)
    if(oddOrEven(number)){
        printf("It's an even number");
    }else{
        printf("It's an odd number");
    }
    return 0;
}
int oddOrEven(int x)
{
    if(x % 2 == 0){
        return 1;
    }else{
        return 0;
    }
}