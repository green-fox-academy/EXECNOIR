#include <stdio.h>


int guessMyNumber(int x, int y);

int main()
{
    int number;
    printf("Gibe number: \n");
    scanf("%d", &number);

    int guess;
    printf("Guess: \n");
    scanf("%d", &guess);
    int value = 2;
    while( value != 0){
        value = guessMyNumber(number, guess);
        scanf("%d", &guess);
    }

    return 0;
}

int guessMyNumber(int x, int y)
{
    if(x > y){
        printf("The stored number is higher.");
        return -1;
    }else if(x < y){
        printf("The stored number is smaller");
        return 1;
    }else{
        printf("Bingo!");
        return 0;
    }
}