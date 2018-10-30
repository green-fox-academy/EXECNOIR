#include <iostream>
#include <string>
#include <algorithm>

std::string reverse(const std::string& text)
{
    std::string valami = text;
    int x = 0;
    int y = valami.size()-1;

    for(int z = 0; z < valami.size()/2; z++){
        std::swap(valami[x],valami[y]);
        x = x+1;
        y = y-1;
    }
    return valami;
}

int main(int argc, char* args[])
{
    std::string reversed = ".eslaf eb t'ndluow ecnetnes siht ,dehctiws erew eslaf dna eurt fo sgninaem eht fI";

    // Create a method that can reverse an std:string, which is passed as the parameter
    // Use it on this reversed string to check it!
    // Try to solve this using .at() first, and optionally anything else after.
    // Hint: You might use a temporary variable to swap 2 characters or you can use std::swap function.

    std::cout << reverse(reversed) << std::endl;

    return 0;
}