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

bool isTriangleMatrix(const int matrix[][MAX_SIZE], unsigned n) {
    unsigned elementsCount = n * n;
    bool isUpperLeftTriangleZeroed = true;
    bool isLowerLeftTriangleZeroed = true;
    bool isUpperRightTriangleZeroed = true;
    bool isLowerRightTriangleZeroed = true;
    bool isTriangle = true;

    for (int i = 0; i < elementsCount; i++) {
        int rowIndex = i / n;
        int colIndex = i % n;

        if (matrix[rowIndex][colIndex] != 0) {
            if (rowIndex + colIndex < n - 1) {
                isUpperLeftTriangleZeroed = false;
            }

            if (rowIndex + colIndex > n - 1) {
                isLowerRightTriangleZeroed = false;
            }

            if (rowIndex < colIndex) {
                isUpperRightTriangleZeroed = false;
            }

            if (rowIndex > colIndex) {
                isLowerLeftTriangleZeroed = false;
            }
        }

        isTriangle = (isUpperLeftTriangleZeroed ||
            isLowerLeftTriangleZeroed ||
            isUpperRightTriangleZeroed ||
            isLowerRightTriangleZeroed);

        if (!isTriangle) {
            return false;
        }
    }

    return isTriangle;
}

int main() {
    unsigned n;
    cin >> n;

    int matrix[MAX_SIZE][MAX_SIZE];
    readSquareMatrix(matrix, n);
    cout << (isTriangleMatrix(matrix, n) ? "true" : "false");
}
