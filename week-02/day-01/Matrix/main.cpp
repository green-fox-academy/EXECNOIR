#include <iostream>
#include <string>

void table(int row, int column);

int main(int argc, char *args[]) {
    int x;
    int y;

    // - Create (dynamically) a two dimensional array
    //   with the following matrix. Use a loop!
    //   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output
    std::cout << "columns" << std::endl;
    std::cin >> x;
    std::cout << "rows" << std::endl;
    std::cin >> y;
    table(x, y);
    return 0;
}

void table(int row, int column) {
    int table[row][column];
    for (int row = 0; row < sizeof(table) / sizeof(table[0]); ++row) {
        for (int column = 0; column < sizeof(table[row]) / sizeof(table[row][0]); ++column) {
            if (row == column) {
                table[row][column] = 1;
            } else {
                table[row][column] = 0;
            }
            std::cout << table[row][column] << " ";
        }

        std::cout << std::endl;
    }
}