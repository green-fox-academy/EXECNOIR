#include <iostream>
#include "Flyable.h"
#include "Helicopter.h"
#include "Vehicle.h"
#include "Animal.h"
#include "Bird.h"
#include "LaysEggs.h"


int main() {
    Bird birb("Elemer");
    Helicopter helicopter(90, 200, Color::BLUE);
    helicopter.takeOff();
    helicopter.fly();
    helicopter.land();
    birb.fly();

}