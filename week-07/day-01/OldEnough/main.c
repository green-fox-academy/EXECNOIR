#include <stdio.h>
#include <stdlib.h>

void canYouBuyAlcohol(int age);

int main()
{
    printf("How old are you?\n");
    int age;
    scanf("%d", &age);
    canYouBuyAlcohol(age);
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    return 0;
}

void canYouBuyAlcohol(int age)
{
    if(age >= 18){
        printf("You can buy alcohol in Hungary.");
    }else{
        printf("You can't buy alcohol in Hungary");
    }
}