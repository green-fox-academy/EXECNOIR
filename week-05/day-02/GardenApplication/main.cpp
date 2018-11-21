#include <iostream>
#include <vector>
#include "Garden.h"
#include "Flower.h"
#include "Tree.h"


int main() {
    Garden garden;
    Flower blueFlower(Color::BLUE);
    Flower yellowFlower(Color::YELLOW);
    Tree purpleTree(Color::PURPLE);
    Tree orangeTree(Color::ORANGE);
    garden.push_back(&blueFlower);
    garden.push_back(&yellowFlower);
    garden.push_back(&purpleTree);
    garden.push_back(&orangeTree);
    garden.getStateAll();
    garden.waterPlants(40);
    garden.getStateAll();
    garden.waterPlants(70);
    garden.getStateAll();
    return 0;
}