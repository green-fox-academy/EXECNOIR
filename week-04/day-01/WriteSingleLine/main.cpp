#include <iostream>
#include <fstream>
#include <string>


int main() {

    std::ofstream MyFile;
    MyFile.open("../my-file.txt");
    if(MyFile.is_open()){
        std::cout << "yay" << std::endl;
    }
    else{
        std::cout << "boo" << std::endl;
    }
    std::string myname = "Gabor Fodor";
    MyFile << myname;
    MyFile.close();
    return 0;
}