#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


std::vector<std::string> filter(std::vector<std::string> list, std::vector<std::string> sweets){
    int x = 0;
    int y = list.size();
    for (int i = 0; i < y; ++i) {

        if((std::find(sweets.begin(),sweets.end(),list[x])) != sweets.end()){


            x = x + 1;}
            else{
            list.erase(list.begin()+x);

            }


        }return list;
}

int main(int argc, char* args[])
{
    const std::vector<std::string> sweets = {"Cupcake", "Brownie"};
    std::vector<std::string> list = {"Cupcake", "Carrot", "Bread", "Brownie", "Lemon"};

    // Accidentally we added "Carrot", "Lemon" and "Bread" to the list.
    // Your task is to remove them from the list. "sweets" vector can help you with this
    // You should erase every element from "list" vector that is not in "sweets" vector.
    // No, don't just remove the lines
    // Create a method called filter() which takes the list as a parameter.

    // Expected output: Cupcake Brownie
    for(const auto& sweet : filter(list, sweets))
    {
        std::cout << sweet << " ";
    }

    return 0;
}