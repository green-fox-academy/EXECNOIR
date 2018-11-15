#include <iostream>

// Given a string, compute recursively a new string where all the
// adjacent chars are now separated by a '*'.
std::string insertAsteriks(std::string text, int x);

int main() {
    std::string text = "asdfghdqweqwweegwetgwtwrtwr";
    std::cout << insertAsteriks(text, 0);
    return 0;
}

std::string insertAsteriks(std::string text, int x){

    if(x > text.length()-1){
        return text;
    }else if( x <= 0 ){
        return insertAsteriks(text, x+1);
    }
    else{
        text.insert(x, "*");
        return insertAsteriks(text, x+2);
    }
}