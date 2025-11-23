#include <iostream>
using namespace std;
const int MAX = 50;

int absoluteValue(int n) {
    return n < 0 ? -n : n;
}

void readSquareMatrix(int matrix[][MAX], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printSquareMatrix(int matrix[][MAX], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void transpose(int matrix[][MAX], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = i + 1; j < size; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void rotate90DegToLeft(int matrix[][MAX], unsigned size) {
    transpose(matrix, size);
    for (unsigned i = 0; i < size / 2; i++) {
        for (unsigned j = 0; j < size; j++) {
            swap(matrix[i][j], matrix[size - 1 - i][j]);
        }
    }
}

void rotate90DegToRight(int matrix[][MAX], unsigned size) {
    transpose(matrix, size);
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size / 2; j++) {
            swap(matrix[i][j], matrix[i][size - 1 - j]);
        }
    }
}

void rotateMatrix(int matrix[][MAX], unsigned size, int degrees) {
    degrees = degrees % 360;
    int rotations = absoluteValue(degrees) / 90;
    if (degrees < 0) {
        for (int i = 0; i < rotations; i++) {
            rotate90DegToLeft(matrix, size);
        }
    }
    else {
        for (int i = 0; i < rotations; i++) {
            rotate90DegToRight(matrix, size);
        }
    }
}

int main() {
    unsigned size;
    cin >> size;
    int matrix[MAX][MAX];
    readSquareMatrix(matrix, size);
    int deg;
    cin >> deg;
    rotateMatrix(matrix, size, deg);
    printSquareMatrix(matrix, size);
}
