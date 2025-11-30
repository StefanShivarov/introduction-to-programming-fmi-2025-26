#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const unsigned MAX_SIZE = 10;

void readSquareMatrix(int matrix[][MAX_SIZE], unsigned n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

bool isSymmetricRelativeToMainDiagonal(const int matrix[][MAX_SIZE], unsigned n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    unsigned n;
    cin >> n;

    int matrix[MAX_SIZE][MAX_SIZE];
    readSquareMatrix(matrix, n);
    cout << (isSymmetricRelativeToMainDiagonal(matrix, n) ? "true" : "false");
}
