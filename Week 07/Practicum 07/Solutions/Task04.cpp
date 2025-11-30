#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const size_t MAX_SIZE = 50;

void readMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplyMatrices(const int first[][MAX_SIZE], size_t r1, size_t c1,
                      const int second[][MAX_SIZE], size_t r2, size_t c2,
                      int result[][MAX_SIZE]) {
    for (size_t i = 0; i < r1; i++) {
        for (size_t j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (size_t k = 0; k < c1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

int main() {
    size_t r1, c1;
    cin >> r1 >> c1;
    int first[MAX_SIZE][MAX_SIZE];
    readMatrix(first, r1, c1);

    size_t r2, c2;
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication is not possible.";
        return -1;
    }

    int second[MAX_SIZE][MAX_SIZE];
    readMatrix(second, r2, c2);

    int result[MAX_SIZE][MAX_SIZE];

    multiplyMatrices(first, r1, c1, second, r2, c2, result);
    printMatrix(result, r1, c2);
}
