#include <stdio.h>
#include <stdlib.h>

int equal(int a, int b);

int main()
{
    int a;
    int b;
    printf("Give me an integer: \n");
    scanf("%d", &a);
    printf("Now, give me another one: \n");
    scanf("%d", &b);

    if(equal(a ,b)){
        printf("The two numbers are equal.");
    }else{
        printf("The two numbers are not equal.");
    }
    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

    return 0;
}

int equal(int a, int b)
{
    if(a == b){
        return 1;
    }else{
        return 0;
    }
}