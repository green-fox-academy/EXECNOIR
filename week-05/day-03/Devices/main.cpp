#include <iostream>
#include "Printer.h"
#include "Printer3D.h"
#include "Printer2D.h"
#include "Copier.h"
#include "Scanner.h"
#include <vector>
int main( int argc, char* args[] )
{
    std::vector<Printer*> printers;
    Printer2D Two1(10, 20);
    Printer2D Two2(15, 10);
    Printer2D Two3(30, 15);
    Printer3D Three1(20, 5, 10);
    Printer3D Three2(10, 15, 5);
    Copier copy1(15, 15, 90);
    printers.push_back(&Two1);
    printers.push_back(&Two2);
    printers.push_back(&Two3);
    printers.push_back(&Three1);
    printers.push_back(&Three2);
    printers.push_back(&copy1);
    for (int i = 0; i < printers.size() ; ++i) {
        printers[i]->print();
    }

    std::vector<Scanner*> scanners;
    Scanner scan1(80);
    Scanner scan2(120);
    Copier copy2(10,10, 100);
    Copier copy3(20,20, 80);

    scanners.push_back(&copy2);
    scanners.push_back(&copy3);
    scanners.push_back(&scan1);
    scanners.push_back(&scan2);

    for (int j = 0; j < scanners.size(); ++j) {
        scanners[j]->scan();
    }

    Copier copy4(5, 5, 130);
    copy4.copy();
    // Create a vector that holds Printer* objects
    // Fill the vector with 3 Printer2D, 2 Printer3D and 1 copier.
    // Iterate through the vector and invoke print function on all of them.

    // Create a vector that holds Scanner* objects
    // Fill the vector with 2 Scanner and 2 Copier objects.
    // Iterate through the vector and invoke scan function on all of them

    // Create a Copier object and invoke copy function on it.
}