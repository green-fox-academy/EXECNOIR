#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters

The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)

Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct house{
    char adress[20];
    int price;
    int rooms;
    int space;
}house_t;

int is_it_worth(house_t house);

int main()
{
    int counter = 0;
    srand(time(0));
    house_t housearray[5];
    for (int i = 0; i < sizeof(housearray)/sizeof(housearray[0]) ; ++i) {
        housearray[i].price = rand()%20000;
        housearray[i].space = rand()&120;
    }
    for (int j = 0; j < sizeof(housearray)/sizeof(housearray[0]) ; ++j) {
        if(is_it_worth(housearray[j])){
            counter ++;
        }
    }

    printf("Number of houses that are worth to buy: %d\n", counter);
    return 0;
}
int is_it_worth(house_t house){
    return house.price/house.space > 400;
}