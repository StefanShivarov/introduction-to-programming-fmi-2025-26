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

void getSumOfEachRow(int matrix[][MAX_SIZE], unsigned rows, unsigned cols, int* rowSums) {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            rowSums[i] += matrix[i][j];
        }
    }
}

int main() {
    unsigned n, m;
    cin >> n >> m;
    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, n, m);
    int rowSums[MAX_SIZE] {0};
    getSumOfEachRow(matrix, n, m, rowSums);
    printArray(rowSums, n);
}
