#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

typedef struct car {
    enum car_type type;
    double km;
    double gas;
} car_t;


void car_data(car_t car);

int main()
{
    car_t car1;
    car1.type = VOLVO;
    car1.km = 200;
    car1.gas = 15;
    car_t car2;
    car2.type = TESLA;
    car2.km = 50;
    car2.gas = 0;

    car_data(car1);
    car_data(car2);

    return 0;
}

void car_data(car_t car)
{   printf("Type; ");
    if(car.type == VOLVO){
        printf("Volvo\n");
    }else if(car.type == TOYOTA){
        printf("Toyota\n");
    }else if(car.type == LAND_ROVER){
        printf("Land Rover\n");
    }else{
        printf("Tesla\n");
    }
    printf("Kilometers: %.1lf\n", car.km);
    if(car.type != TESLA){
        printf("Gas amount: %.1lf\n", car.gas );
    }
}