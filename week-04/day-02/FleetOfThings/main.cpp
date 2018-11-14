#include <iostream>

#include "Fleet.h"

int main(int argc, char* args[])
{
    Fleet fleet;
    // Create a fleet of things to have this output:
    // 1. [ ] Get milk
    // 2. [ ] Remove the obstacles
    // 3. [x] Stand up
    // 4. [x] Eat lunch
    Thing milk("Get milk");
    Thing obstacle("Remove the obstacles");
    Thing standup("Stand up");
    standup.complete();
    Thing lunch("Eat lunch");
    lunch.complete();
    fleet.add(milk);
    fleet.add(obstacle);
    fleet.add(standup);
    fleet.add(lunch);
    std::cout << fleet.toString() << std::endl;
    return 0;
}