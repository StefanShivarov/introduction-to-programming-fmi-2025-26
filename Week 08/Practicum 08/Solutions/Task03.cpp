#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_SIZE = 50;

void readSquareMatrix(int matrix[][MAX_SIZE], unsigned size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printSpiralFromCenter(const int matrix[][MAX_SIZE], unsigned size) {
    int top = size / 2, bottom = size / 2, left = size / 2, right = size / 2;
    while (true) {
        if (bottom >= size) {
            break;
        }
        for (int i = right; i >= left; i--) {
            cout << matrix[bottom][i] << ' ';
        }
        left--;

        if (left < 0) {
            break;
        }
        for (int i = bottom; i >= top; i--) {
            cout << matrix[i][left] << ' ';
        }
        top--;

        if (top < 0) {
            break;
        }
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << ' ';
        }
        right++;

        if (right >= size) {
            break;
        }
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << ' ';
        }
        bottom++;
    }
}


int main() {
    unsigned n;
    cin >> n;

    int matrix[MAX_SIZE][MAX_SIZE];
    readSquareMatrix(matrix, n);

    printSpiralFromCenter(matrix, n);
}
