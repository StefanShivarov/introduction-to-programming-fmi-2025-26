#include <iostream>
using namespace std;

const int MAX = 100;

void printMatrix(const int matrix[][MAX], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void readMatrix(int matrix[][MAX], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

double getAverageOfSubmatrix(const int matrix[][MAX], unsigned submatrixSize, unsigned startRow, unsigned startCol) {
    int sum = 0;
    for (unsigned i = startRow; i < startRow + submatrixSize; i++) {
        for (unsigned j = startCol; j < startCol + submatrixSize; j++) {
            sum += matrix[i][j];
        }
    }
    int denominator = submatrixSize * submatrixSize;
    return (double)sum / denominator;
}

void printSubmatrix(const int matrix[][MAX], unsigned submatrixSize, unsigned startRow, unsigned startCol) {
    for (unsigned i = startRow; i < startRow + submatrixSize; i++) {
        for (unsigned j = startCol; j < startCol + submatrixSize; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printSubmatrixWithHighestAverage(const int matrix[][MAX], unsigned size, unsigned submatrixSize) {
    unsigned maxAvgRow = 0, maxAvgCol = 0;
    double maxAvg = -1e18;

    for (unsigned i = 0; i <= size - submatrixSize; i++) {
        for (unsigned j = 0; j <= size - submatrixSize; j++) {
            double currentAvg = getAverageOfSubmatrix(matrix, submatrixSize, i, j);
            if (currentAvg > maxAvg) {
                maxAvg = currentAvg;
                maxAvgRow = i;
                maxAvgCol = j;
            }
        }
    }
    printSubmatrix(matrix, submatrixSize, maxAvgRow, maxAvgCol);
}

int main() {
    unsigned n;
    cin >> n;
    int matrix[MAX][MAX];
    readMatrix(matrix, n);

    unsigned m;
    cin >> m;
    printSubmatrixWithHighestAverage(matrix, n, m);
    return 0;
}
