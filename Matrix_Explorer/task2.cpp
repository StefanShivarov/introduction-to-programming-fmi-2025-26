#include <iostream>
using namespace std;

int main() {
    int matrix[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> matrix[i][j];
    for (int i = 0; i < 4; i++) {
        int counter = 0;
        for (int j = 0; j < 4; j++)
            if (matrix[i][j] < 0)
                counter++;
        cout << counter << " ";
    }

}