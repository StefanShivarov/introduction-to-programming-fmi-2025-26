#include <iostream>

using namespace std;

int main() {
    int size = 0;
    cin >> size;

    for (int row = 0; row <= size; row++) {
        for (int left = 0; left < size; left++) {
            char symbol = (left < size - row) ? ' ' : '*';
            cout << symbol;
        }
        cout << " | ";
        for (int right = 0; right < size; right++) {
            char symbol = (right > row - 1) ? ' ' : '*';
            cout << symbol;
        }

        cout << endl;
    }

    return 0;
}