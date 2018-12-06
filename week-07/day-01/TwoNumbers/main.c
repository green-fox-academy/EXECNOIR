#include<stdio.h>

int main()
{
    // Create a program that prints a few operations on two numbers: 22 and 13

    // Print the result of 13 added to 22

    // Print the result of 13 substracted from 22

    // Print the result of 22 multiplied by 13

    // Print the result of 22 divided by 13 (as a decimal fraction)

    // Print the reminder of 22 divided by 13

    // Store the results in variables and use them when you display the result

    int a = 22;
    int b = 13;

    int sum = a + b;
    printf("%d\n", sum);

    int subt = a - b;
    printf("%d\n", subt);

    int multip = a*b;
    printf("%d\n", multip);

    int div = a / b;
    printf("%d\n", div);

    int rem = 22 % 13; //best girl
    printf("Reminder: Divide 22 by 13!!!!!\n........okay, okay...\nIt's %d", rem);



    return 0;
}