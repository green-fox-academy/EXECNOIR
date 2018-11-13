#include <iostream>
#include "PostIt.h"
int main() {
    PostIt PostIt1("Blue", "Idea 1", "Orange");
    PostIt PostIt2("Black", "Awesome", "Pink");
    PostIt PostIt3("Green", "Superb", "Yellow");


    std::cout << "First Post it; " << "Background Color: " <<PostIt1.GetBackgroundColor() << std::endl <<
    "Text: " << PostIt1.GetText() << std::endl <<
    "Text Color :" << PostIt1.GetTextColor() << std::endl;

    std::cout << "Second Post it; " << "Background Color: " <<PostIt2.GetBackgroundColor() << std::endl <<
              "Text: " << PostIt2.GetText() << std::endl <<
              "Text Color :" << PostIt2.GetTextColor() << std::endl;

    std::cout << "Third Post it; " << "Background Color: " <<PostIt3.GetBackgroundColor() << std::endl <<
              "Text: " << PostIt3.GetText() << std::endl <<
              "Text Color :" << PostIt3.GetTextColor() << std::endl;







    return 0;
}