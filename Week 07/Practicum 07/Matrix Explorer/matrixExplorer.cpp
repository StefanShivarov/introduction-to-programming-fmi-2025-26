#include <iostream>
using namespace std;

const int MAX = 10;

void printMatrix(const int matrix[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int sumAll(const int matrix[][MAX], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

double average(const int matrix[][MAX], int n) {
    int total = sumAll(matrix, n);
    return (double)total / (n * n);
}

void printRowSums(const int matrix[][MAX], int n) {
    cout << "Row sums: ";
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
}

void printColSums(const int matrix[][MAX], int n) {
    cout << "Column sums: ";
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += matrix[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
}

int getMin(const int matrix[][MAX], int n) {
    int minVal = matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
            }
        }
    }
    return minVal;
}

int getMax(const int matrix[][MAX], int n) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

int mainDiagonalSum(const int matrix[][MAX], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

int secondaryDiagonalSum(const int matrix[][MAX], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][n - 1 - i];
    }
    return sum;
}

void transpose(int matrix[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void rotateMatrix(int matrix[][MAX], int n) {
    // Step 1: Transpose
    transpose(matrix, n);
    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}

int main() {
    int n;
    int matrix[MAX][MAX];

    cout << "Enter matrix size (n <= 10): ";
    cin >> n;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    printMatrix(matrix, n);

    cout << "\nTotal sum: " << sumAll(matrix, n);
    cout << "\nAverage: " << average(matrix, n) << endl;

    printRowSums(matrix, n);
    printColSums(matrix, n);

    cout << "\nMinimum element: " << getMin(matrix, n);
    cout << "\nMaximum element: " << getMax(matrix, n) << endl;

    cout << "\nMain diagonal sum: " << mainDiagonalSum(matrix, n);
    cout << "\nSecondary diagonal sum: " << secondaryDiagonalSum(matrix, n);
    cout << "\nDifference: " << mainDiagonalSum(matrix, n) - secondaryDiagonalSum(matrix, n) << endl;

    cout << "\nTransposed Matrix:\n";
    transpose(matrix, n);
    printMatrix(matrix, n);

    cout << "\nRotated Matrix (90 degrees clockwise):\n";
    rotateMatrix(matrix, n);
    printMatrix(matrix, n);

    return 0;
}
