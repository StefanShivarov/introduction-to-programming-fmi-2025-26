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

void printArray(const int* arr, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void countNegativeNumbersPerRow(int matrix[][MAX_SIZE], unsigned rows, unsigned cols, int* oddCounts) {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            if (matrix[i][j] < 0) {
                oddCounts[i]++;
            }
        }
    }
}

int main() {
    unsigned n, m;
    cin >> n >> m;
    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, n, m);
    int oddCounts[MAX_SIZE] {0};
    countNegativeNumbersPerRow(matrix, n, m, oddCounts);
    printArray(oddCounts, n);
}
