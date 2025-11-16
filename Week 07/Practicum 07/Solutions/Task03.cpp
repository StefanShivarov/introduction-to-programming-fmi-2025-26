#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_SIZE = 50;

void readMatrix(int matrix[][MAX_SIZE], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void pow2EvenNums(int matrix[][MAX_SIZE], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            if (matrix[i][j] % 2 == 0) {
                matrix[i][j] *= matrix[i][j];
            }
        }
    }
}

void printMatrix(int matrix[][MAX_SIZE], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    unsigned n, m;
    cin >> n >> m;
    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, n, m);
    pow2EvenNums(matrix, n, m);
    printMatrix(matrix, n, m);
}
