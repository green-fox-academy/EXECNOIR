#include <iostream>
#include <fstream>
#include <string>

int CountLines(std::string path);

int main () {

    std::string filename = "../cucc.txt";
    std::cout << CountLines(filename) << std::endl;
    return 0;
}

int CountLines(std::string path){
    std::string text;
    std::ifstream myfile(path);
    int counter = 0;
    if(!myfile.is_open()){
        return 0;
    }
    while(getline(myfile, text)){
        counter ++;
    }return counter;
}