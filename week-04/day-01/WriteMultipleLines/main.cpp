#include <iostream>
#include <fstream>
#include <string>

  // Create a function that takes 3 parameters: a path, a word and a number,
  // than it should write to a file.
  // The path parameter should describes the location of the file.
  // The word parameter should be a string, that will be written to the file as lines
  // The number paramter should describe how many lines the file should have.
  // So if the word is "apple" and the number is 5, than it should write 5 lines
  // to the file and each line should be "apple"



  bool newfile(std::string path, std::string word, int numberoflines );

int main() {
    std::string path;
    std::string word;
    int number;
    std::cout << "please give me the path to your file" << std::endl;
    std::cin >> path;
    std::cout << "please give me a word" << std::endl;
    std::cin >> word;
    std::cout << "Please give me an integer" << std::endl;
    std::cin >> number;
    if(!newfile(path, word, number)){
        return 2;
    }

    return 0;
}
bool newfile(std::string path, std::string word, int numberoflines ){
    std::ofstream myfile;
    myfile.open (path);
    if(!myfile.is_open()){
        std::cout << "File cannot be accessed!" << std::endl;
        return false;
    }

    for (int i = 0; i < numberoflines ; ++i) {
        myfile << word << std::endl;
    }
    myfile.close();
    return true;
}
