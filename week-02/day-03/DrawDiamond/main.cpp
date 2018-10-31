#include <iostream>
using namespace std;

int main()
{
    int space, rows;

    cout <<"Enter number of rows: ";
    cin >> rows;
        for (int i = 1, k = 0; i <= rows - rows / 2; ++i, k = 0) {
            for (space = 1; space <= rows - rows / 2 - i; ++space) {
                cout << " ";
            }

            while (k != 2 * i - 1) {
                cout << "*";
                ++k;
            }
            cout << endl;
        }
        for (int j = rows - rows / 2, k = 0; j >= 1; --j, k = 0) {

            for (space = 1; space <= rows - rows / 2 - j; ++space) {
                cout << " ";
            }

            while (k != 2 * j - 1) {
                cout << "*";
                ++k;
            }
            cout << endl;

        }



    return 0;
}