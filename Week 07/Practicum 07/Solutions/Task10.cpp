#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const unsigned MAX_SIZE = 10;

void readMatrix(int matrix[][MAX_SIZE], unsigned rows, unsigned cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

bool areAllDiagonalsStrictlyIncreasing(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int startRow = 0; startRow < rows; ++startRow) {
        int row = startRow;
        int col = 0;
        int prev = matrix[row][col];

        while (row >= 0 && col < cols) {
            if (row != startRow && prev >= matrix[row][col]) {
                return false;
            }
            prev = matrix[row][col];
            row--;
            col++;
        }
    }

    for (int startCol = 1; startCol < cols; ++startCol) {
        int row = rows - 1;
        int col = startCol;
        int prev = matrix[row][col];

        while (row >= 0 && col < cols) {
            if (col != startCol && prev >= matrix[row][col]) {
                return false;
            }
            prev = matrix[row][col];
            row--;
            col++;
        }
    }

    return true;
}

int main() {
    unsigned rows, cols;
    cin >> rows >> cols;

    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, rows, cols);
    cout << (areAllDiagonalsStrictlyIncreasing(matrix, rows, cols) ? "true" : "false");
}
