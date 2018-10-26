#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    double a = 24;
    int out = 0;
    // if a is even increment out by one
    if ((int) a % 2 == 0) { out++; };
    std::cout << out << std::endl;


    std::string out2 = "";
    int b = 13;
    if (b > 10) {
        if (b < 20) { out2 = "Sweet!"; };
        if (b > 20) { out2 = "More!"; };
    } else { out2 = "Less!"; };
    // if b is between 10 and 20 set out2 to "Sweet!"
    // if less than 10 set out2 to "Less!",
    // if more than 20 set out2 to "More!"

    std::cout << out2 << std::endl;


    int c = 123;
    int credits = 100;
    bool isBonus = false;
    // if credits are at least 50,
    // and isBonus is false decrement c by 2
    // if credits are smaller than 50,
    // and isBonus is false decrement c by 1
    // if isBonus is true c should remain the same
    if (isBonus == false) {
        if (credits >= 50 && isBonus == false) { c = c - 2; };
        if (credits < 50 && isBonus == false) { c = c - 1; };
    };

    std::cout << c << std::endl;


    int d = 8;
    int time = 120;
    std::string out3 = "";
    // if d is dividable by 4
    // and time is not more than 200
    // set out3 to "check"
    // if time is more than 200
    // set out3 to "Time out"
    // otherwise set out3 to "Run Forest Run!"
    if(d%4 != 0 && time < 200){out3 = "Check";};




    std::cout << out3 << std::endl;

    return 0;
}