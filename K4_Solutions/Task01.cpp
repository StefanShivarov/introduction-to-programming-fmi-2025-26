#include <iostream>
using namespace std;

bool isPerfect(int n) {
    if (n <= 1) {
        return false;
    }

    int sum = 1;
    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            sum += d;
            if (d != n / d) {
                sum += n / d;
            }
        }
    }
    return sum == n;
}

int* collectPerfectNumbers(int** matrix, int rows, int cols, int& resultSize) {
    resultSize = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isPerfect(matrix[i][j])) {
                resultSize++;
            }
        }
    }

    int* result = new int[resultSize];
    int index = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isPerfect(matrix[i][j])) {
                result[index++] = matrix[i][j];
            }
        }
    }

    return result;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int resultSize;
    int* result = collectPerfectNumbers(matrix, rows, cols, resultSize);

    for (int i = 0; i < resultSize; i++) {
        cout << result[i] << " ";
    }

    delete[] result;
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}
