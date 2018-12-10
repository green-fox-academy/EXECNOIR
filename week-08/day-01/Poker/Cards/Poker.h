//
// Created by EXEC_NOIR on 12/10/2018.
//

#ifndef POKER_POKER_H
#define POKER_POKER_H
#include <vector>
#include "Cards.h"
#include <map>

int checkHighCard(std::vector<Cards> p1_hand, std::vector<Cards> p2_hand);
int checkPair(std::vector<Cards> p1_hand, std::vector<Cards> p2_hand);
#endif //POKER_POKER_H
