#include <stdio.h>
#include <string.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)

Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

typedef struct sandwich {
    char name[20];
    float price;
    float weight;
}sandwich_t;

int order_price(sandwich_t sandwich, int amount);

int main()
{
    sandwich_t sandwich;
    strcpy(sandwich.name, "sonkas");
    sandwich.price = 200;
    sandwich.weight = 2;

    printf("Price: %d", order_price(sandwich, 3));
    return 0;
}

int order_price(sandwich_t sandwich, int amount)
{
    return sandwich.price*amount;
}