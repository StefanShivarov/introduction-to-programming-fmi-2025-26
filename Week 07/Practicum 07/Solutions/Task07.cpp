#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_SIZE = 50;

void readMatrix(int matrix[][MAX_SIZE], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

int getSumOfDiagonalNumbers(const int matrix[][MAX_SIZE], unsigned size) {
    int sum = 0;
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) {
            if (i == j || i + j == size - 1) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int main() {
    unsigned n;
    cin >> n;
    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, n);
    cout << getSumOfDiagonalNumbers(matrix, n);
}
