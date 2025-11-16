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

int getSumOfRowNumbers(const int matrix[][MAX_SIZE], unsigned size, unsigned row) {
    int sum = 0;
    for (unsigned i = 0; i < size; i++) {
        sum += matrix[row][i];
    }
    return sum;
}

int getSumOfColNumbers(const int matrix[][MAX_SIZE], unsigned size, unsigned col) {
    int sum = 0;
    for (unsigned i = 0; i < size; i++) {
        sum += matrix[i][col];
    }
    return sum;
}

bool areRowSumsEqual(const int matrix[][MAX_SIZE], unsigned size) {
    int rowSum = getSumOfRowNumbers(matrix, size, 0);
    for (unsigned i = 1; i < size; i++) {
        if (getSumOfRowNumbers(matrix, size, i) != rowSum) {
            return false;
        }
    }
    return true;
}

bool areColSumsEqual(const int matrix[][MAX_SIZE], unsigned size) {
    int colSum = getSumOfColNumbers(matrix, size, 0);
    for (unsigned i = 1; i < size; i++) {
        if (getSumOfColNumbers(matrix, size, i) != colSum) {
            return false;
        }
    }
    return true;
}

bool areDiagonalSumsEqual(const int matrix[][MAX_SIZE], unsigned size) {
    int mainDiagSum = 0, secondaryDiagSum = 0;
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) {
            if (i == j) {
                mainDiagSum += matrix[i][j];
            }
            if (i + j == size - 1) {
                secondaryDiagSum += matrix[i][j];
            }
        }
    }
    return mainDiagSum == secondaryDiagSum;
}

bool isMagicMatrix(const int matrix[][MAX_SIZE], unsigned size) {
    return areRowSumsEqual(matrix, size)
            && areColSumsEqual(matrix, size)
            && areDiagonalSumsEqual(matrix, size);
}

int main() {
    unsigned n;
    cin >> n;
    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, n);
    cout << (isMagicMatrix(matrix, n) ? "magic" : "not magic");
}
