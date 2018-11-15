#include <iostream>
#include <string>

// Given a string, compute recursively (no loops) a new string where all the
// lowercase 'x' chars have been changed to 'y' chars.
std::string XtoY(std::string szoveg, int x);

int main() {
    std::string cucc = "xxxDarkSasukexxx";
    std::cout << XtoY(cucc, cucc.length()) << std::endl;
    return 0;
}

std::string XtoY(std::string szoveg, int x) {

    if (x <= -1) {
        return szoveg;
    } else if (szoveg[x] == 'x') {
        szoveg[x] = 'y';
        return XtoY(szoveg, x - 1);
    } else {
        return XtoY(szoveg, x - 1);
    }
}

