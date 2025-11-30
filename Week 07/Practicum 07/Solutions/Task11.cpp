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

void printSpiralFromBottomRightAnticlockwise(const int matrix[][MAX_SIZE], unsigned rows, unsigned cols) {
    int top = 0, left = 0, right = cols - 1, bottom = rows - 1;
    while (top <= bottom && left <= right) {
        for (int i = bottom; i >= top; i--) {
            cout << matrix[i][right] << ' ';
        }
        right--;

        for (int i = right; i >= left; i--) {
            cout << matrix[top][i] << ' ';
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][left] << ' ';
        }
        left++;

        for (int i = left; i <= right; i++) {
            cout << matrix[bottom][i] << ' ';
        }
        bottom--;
    }
}

int main() {
    unsigned n, m;
    cin >> n >> m;
    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, n, m);
    printSpiralFromBottomRightAnticlockwise(matrix, n, m);
}
