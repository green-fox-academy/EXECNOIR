#include <stdio.h>
#include <stdlib.h>

int sumOfDigits(int x, int value);
int equalSums(int x, int y);

int main()
{
    int number1;
    int number2;
    printf("Give me a number: \n");
    scanf("%d", &number1);
    printf("Give me another number: \n");
    scanf("%d", &number2);

    int result1 = sumOfDigits(number1, 0);
    int result2 = sumOfDigits(number2, 0);
    printf("sum of the first numbers digits: %d\n", result1);
    printf("sum of the second numbers digits: %d\n", result2);
    if(equalSums(result1, result2)) {
        printf("The sums of the two numbers are equal!\n");
    }else{
        printf("The sums of the two numbers are not equal!\n");
    }

    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    //
    // For example:
    //
    // Case 1:
    //
    // a = 123
    // b = 321
    //
    // sum of number of digits (variable a) = 1 + 2 + 3 = 6
    // sum of number of digits (variable b) = 3 + 2 + 1 = 6
    // in this case the function should return 1
    //
    //
    // Case 2:
    //
    // a = 723
    // b = 114
    //
    // sum of number of digits (variable a) = 7 + 2 + 3 = 12
    // sum of number of digits (variable b) = 1 + 1 + 4 = 6
    // in this case the function should return 0

    return 0;
}

int sumOfDigits(int x, int value)
{
    if(x/10 == 0){
        return value+x%10;
    }else{
        value = value+x%10;
        return sumOfDigits(x/10, value);
    }
}
int equalSums(int x, int y)
{
    if(x == y){
        return 1;
    }else{
        return 0;
    }
}