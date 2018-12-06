#include <stdio.h>
#include <stdlib.h>

int isItPrime(int x);

int main()
{
    int number;
    printf("Give me a number!\n");
    scanf("%d", &number);

    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    if(isItPrime(number)){
        printf("It's a prime number.");
    }else{
        printf("It's not a prime number,");
    }
    return 0;
}
int isItPrime(int x)
{
    printf("Your number is: %d\n", x);
    if(x == 1)
    {
        printf("It's 1....\n");
        return 0;
    }else{
        for (int i = 2; i <= x/2; ++i) {
            if(x%i == 0){
                return 0;
            }


        }return 1;
    }
}