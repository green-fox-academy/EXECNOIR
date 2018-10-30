#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {

    std::vector<int> jani =  {1, 2, 3, 4, 5};


        if((std::find(jani.begin(), jani.end(),5)) != jani.end())
        {
            std::cout << "ot" << std::endl;
        }
        else{
            std::cout << "nincs ot" << std::endl;
        }


    return 0;
}