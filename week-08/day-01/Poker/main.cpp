#include <iostream>
#include "Cards.h"
#include <vector>



int main() {
    Cards p1_card1(Value::TWO, Suite::HEART);
    Cards p1_card2(Value::THREE, Suite::DIAMOND);
    Cards p1_card3(Value::FIVE, Suite::SPADE);
    Cards p1_card4(Value::NINE, Suite::CLUB);
    Cards p1_card5(Value::KING, Suite::DIAMOND);
    std::vector<Cards> p1_hand;
    p1_hand.push_back(p1_card1);
    p1_hand.push_back(p1_card2);
    p1_hand.push_back(p1_card3);
    p1_hand.push_back(p1_card4);
    p1_hand.push_back(p1_card5);


    Cards p2_card1(Value::TWO, Suite::CLUB);
    Cards p2_card2(Value::THREE, Suite::HEART);
    Cards p2_card3(Value::FOUR, Suite::SPADE);
    Cards p2_card4(Value::EIGHT, Suite::CLUB);
    Cards p2_card5(Value::ACE, Suite::HEART);
    std::vector<Cards> p2_hand;
    p2_hand.push_back(p2_card1);
    p2_hand.push_back(p2_card2);
    p2_hand.push_back(p2_card3);
    p2_hand.push_back(p2_card4);
    p2_hand.push_back(p2_card5);
    return 0;
}

