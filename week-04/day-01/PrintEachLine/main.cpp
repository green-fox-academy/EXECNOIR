#include <iostream>
#include <fstream>
#include <string>

int main () {

    std::ifstream myfile;
    myfile.open("../my-file.txt");
    if(myfile.is_open()){
        std::cout << "yay" << std::endl;
    }
    else{
        std::cout << "boo" << std::endl;
    }
    std::string text;
    while(getline (myfile, text)) {
        std::cout << text << std::endl;
    }
    myfile.close();



    // Write a program that opens a file called "my-file.txt", then prints
    // each of lines form the file.
    // You have to create the file, you can use C-programming but it is not mandatory

    return 0;
}