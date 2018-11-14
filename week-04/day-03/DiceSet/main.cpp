#include <iostream>

#include "dice_set.h"

int main(int argc, char* args[])
{
    // You have a `DiceSet` class which has a list for 6 dices
    // You can roll all of them with roll()
    // Check the current rolled numbers with getCurrent()
    // You can reroll with roll()
    // Your task is to roll the dices until all of the dices are 6
    DiceSet diceSet;
    diceSet.roll();
    int diceNumber = 0;
    while(diceSet.getCurrent(diceNumber) != 6 || diceNumber < 6) {

        if (diceSet.getCurrent(diceNumber) == 6) {

            diceNumber += 1;
        }else {
            diceSet.roll(diceNumber);
        }
    }
    for (int i = 0; i < diceSet.getCurrent().size(); ++i) {
        std::cout << i+1 << ". Dice: " << diceSet.getCurrent(i) << std::endl;
    }
    return 0;
}