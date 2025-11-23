#include <iostream>
using namespace std;

const int MAX = 50;

void swap(unsigned& a, unsigned& b) {
    unsigned t = a;
    a = b;
    b = t;
}

int absoluteValue(int n) {
    return n < 0 ? -n : n;
}

void readMatrix(int matrix[][MAX], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void copyMatrix(const int src[][MAX], int dest[][MAX], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

void printMatrix(int matrix[][MAX], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void transpose(int matrix[][MAX], unsigned rows, unsigned cols) {
    int temp[MAX][MAX];

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            temp[j][i] = matrix[i][j];
        }
    }

    copyMatrix(temp, matrix, rows, cols);
}

void rotate90DegToLeft(int matrix[][MAX], unsigned& rows, unsigned& cols) {
    int temp[MAX][MAX];

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            temp[cols - 1 - j][i] = matrix[i][j];
        }
    }

    swap(rows, cols);
    copyMatrix(temp, matrix, rows, cols);
}

void rotate90DegToRight(int matrix[][MAX], unsigned& rows, unsigned& cols) {
    int temp[MAX][MAX];

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            temp[j][rows - 1 - i] = matrix[i][j];
        }
    }

    swap(rows, cols);
    copyMatrix(temp, matrix, rows, cols);
}

void rotateMatrix(int matrix[][MAX], unsigned& rows, unsigned& cols, int degrees) {
    degrees = degrees % 360;
    int rotations = absoluteValue(degrees) / 90;

    if (degrees < 0) {
        for (int i = 0; i < rotations; i++) {
            rotate90DegToLeft(matrix, rows, cols);
        }
        return;
    }
    for (int i = 0; i < rotations; i++) {
        rotate90DegToRight(matrix, rows, cols);
    }
}

int main() {
    unsigned rows, cols;
    cin >> rows >> cols;

    int matrix[MAX][MAX];
    readMatrix(matrix, rows, cols);

    int deg;
    cin >> deg;

    rotateMatrix(matrix, rows, cols, deg);
    printMatrix(matrix, rows, cols);
    return 0;
}
