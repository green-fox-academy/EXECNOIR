//
// Created by EXEC_NOIR on 12/10/2018.
//

#include "Poker.h"

int checkHighCard(std::vector<Cards> p1_hand, std::vector<Cards> p2_hand)
{
    Value p1_counter = Value::TWO;
    Value p2_counter = Value::TWO;
    for (int i = 0; i < 5; ++i) {
        if(p1_hand[i].getValue() > p1_counter){
            p1_counter = p1_hand[i].getValue();
        }
        if(p2_hand[i].getValue() > p2_counter){
            p2_counter = p2_hand[i].getValue();
        }
    }
    if(p1_counter > p2_counter){
        return 1;
    }else if(p1_counter < p2_counter){
        return 2;
    }else{
        return 0;
    }
};

int checkPair(std::vector<Cards> p1_hand, std::vector<Cards> p2_hand)
{
    std::map<Value, int> hand1;
    std::map<Value, int> hand2;

    for (int i = 0; i < p1_hand.size(); ++i) {
        if ( hand1.find(p1_hand[i].getValue()) == hand1.end() ) {
            hand1.insert(std::pair<Value, int>(p1_hand[i].getValue(), 1));
        }else {
            hand1[p1_hand[i].getValue()]++;
        }
    }
    for (int i = 0; i < p2_hand.size(); ++i) {
        if ( hand2.find(p2_hand[i].getValue()) == hand2.end() ) {
            hand2.insert(std::pair<Value, int>(p2_hand[i].getValue(), 1));
        }else {
            hand2[p2_hand[i].getValue()]++;
        }
    }
    int counter1 = 0;
    int counter2 = 0;
    for(auto p : hand1){
        if(p.second == 2){
            counter1++;
        }
    }
    for(auto p : hand2){
        if(p.second == 2){
            counter2++;
        }
    }
    if(counter1 > counter2){
        return 1;
    }else if(counter1 < counter2){
        return 2;
    }else return 0;
}
