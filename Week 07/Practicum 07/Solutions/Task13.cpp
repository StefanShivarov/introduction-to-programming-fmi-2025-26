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

void printMatrix(const int matrix[][MAX_SIZE], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (i != minIndex) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void extractMatrixToArray(const int matrix[][MAX_SIZE], unsigned rows, unsigned cols, int* arr) {
    unsigned index = 0;
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            arr[index++] = matrix[i][j];
        }
    }
}

void populateMatrixFromArray(int matrix[][MAX_SIZE], unsigned rows, unsigned cols, const int* arr) {
    unsigned index = 0;
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            matrix[i][j] = arr[index++];
        }
    }
}

void sortMatrix(int matrix[][MAX_SIZE], unsigned rows, unsigned cols) {
    int arr[MAX_SIZE * MAX_SIZE];
    extractMatrixToArray(matrix, rows, cols, arr);
    selectionSort(arr, rows * cols);
    populateMatrixFromArray(matrix, rows, cols, arr);
}

int main() {
    unsigned n, m;
    cin >> n >> m;
    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, n, m);
    sortMatrix(matrix, n, m);
    printMatrix(matrix, n, m);
}
