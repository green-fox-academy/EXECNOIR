#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

bool copy(std::string inputfile, std::string outputfile);

int main() {
    std::string pathIn;
    std::string pathOut;
    std::cout << "input file path:" << std::endl;
    std::cin >> pathIn;
    std::cout << "output file path:" << std::endl;
    std::cin >> pathOut;

    if(!copy(pathIn, pathOut)){
        return 2;
    }
    return 0;
}
bool copy(std::string inputfile, std::string outputfile){

    std::ifstream FileOrigin(inputfile);
    std::ofstream FileCopy(outputfile);
    std::string lines;
    if(!FileCopy.is_open() && FileOrigin.is_open()){
        std::cout << "Copy unsuccessful, try again!" << std::endl;
        return false;
    }
    while(getline(FileOrigin, lines)){

        FileCopy << lines << std::endl;
    }
    FileCopy.close();
    FileOrigin.close();
    return true;
}