#include <iostream>
#include <string>

// Given a string, compute recursively a new string where all the 'x' chars have been removed.
std::string XtoY(std::string szoveg, int x);

int main() {
    std::string cucc = "xx1xx2xxfxxexxp";
    std::cout << XtoY(cucc, cucc.length()) << std::endl;
    return 0;
}

std::string XtoY(std::string szoveg, int x) {

    if (x <= 0) {

        return szoveg;
    } else if (szoveg[x] == 'x') {
        szoveg.erase(x, 1);
        return XtoY(szoveg, x - 1);
    } else {
        return XtoY(szoveg, x - 1);
    }
}

