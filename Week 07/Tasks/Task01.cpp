#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 50;

unsigned findMaxInRowIndex(const int matrix[][MAX_SIZE], unsigned size, unsigned rowIndex) {
    unsigned maxNumIndex = 0;
    for (unsigned i = 1; i < size; i++) {
        if (matrix[rowIndex][i] > matrix[rowIndex][maxNumIndex]) {
            maxNumIndex = i;
        }
    }
    return maxNumIndex;
}

unsigned findMinInColIndex(const int matrix[][MAX_SIZE], unsigned size, unsigned colIndex) {
    unsigned minNumIndex = 0;
    for (unsigned i = 1; i < size; i++) {
        if (matrix[i][colIndex] < matrix[minNumIndex][colIndex]) {
            minNumIndex = i;
        }
    }
    return minNumIndex;
}

void printSaddlePointCoordinates(const int matrix[][MAX_SIZE], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        unsigned maxNumInRowIndex = findMaxInRowIndex(matrix, size, i);
        unsigned minNumInColIndex = findMinInColIndex(matrix, size, maxNumInRowIndex);
        if (minNumInColIndex == i) {
            cout << minNumInColIndex << " " << maxNumInRowIndex << endl;
        }
    }
}

void readSquareMatrix(int matrix[][MAX_SIZE], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    readSquareMatrix(matrix, 4);
    printSedlova(matrix, 4);
}
