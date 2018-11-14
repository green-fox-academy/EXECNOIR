#include <iostream>
#include "Car.h"
#include "Station.h"
#include <vector>

int main() {
    Station station(250);
    std::vector<Car> carpark;
    carpark.push_back(Car(80, 100));
    carpark.push_back(Car(70, 80));
    carpark.push_back(Car(20, 50));
    carpark.push_back(Car(50, 60));
    carpark.push_back(Car(10, 90));

    for(auto p : carpark){
        station.Fill(p);
    }

    return 0;
}