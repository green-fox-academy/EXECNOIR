#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP adresses.
// Write a function that returns the GET / POST request ratio.

std::vector<std::string> ipadress(std::string logfile);
float getpostratio(std::string logfile);

int main() {
    std::string path = "../log.txt";
    int counter = 0;

    std::vector<std::string> janos = ipadress(path);

    for(auto ip : ipadress(path)){
        counter = counter +1;
        std::cout << counter << " " <<ip << std::endl;
    }
    std::cout << "The GET to POST ratio is " << getpostratio(path) << std::endl;
    return 0;
}
std::vector<std::string> ipadress(std::string logfile){

    std::ifstream myfile(logfile);
    std::string day;
    std::string month;
    int five;
    std::string time;
    int year;
    std::string ipadress;
    std::string getpost;
    std::string slash;
    std::vector<std::string> allipadress;
    while(myfile >> day >> month >> five >> time >> year >> ipadress >> getpost >> slash) {
        if (std::find(allipadress.begin(), allipadress.end(), ipadress) == allipadress.end()) {
            allipadress.push_back(ipadress);
        }
    }
    myfile.close();
    return allipadress;

}

float getpostratio(std::string logfile){
    std::string day;
    std::string month;
    int five;
    std::string time;
    int year;
    std::string ipadress;
    std::string getpost;
    std::string slash;
    std::ifstream myfile(logfile);
    float getcounter = 0;
    float postcounter = 0;
    while(myfile >> day >> month >> five >> time >> year >> ipadress >> getpost >> slash){
        if(getpost == "GET"){
            getcounter = getcounter + 1;
        }
        if(getpost == "POST"){
            postcounter = postcounter + 1;
        }
    }float ratio = getcounter / postcounter;
    myfile.close();
    return ratio;
}
