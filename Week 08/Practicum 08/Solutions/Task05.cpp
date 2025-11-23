#include <iostream>
using namespace std;

const int MAX = 100;

void readMatrix(int matrix[][MAX], unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

int getSubmatrixSum(const int matrix[][MAX], unsigned p, unsigned q, unsigned startRow, unsigned startCol) {
    int sum = 0;
    for (unsigned i = startRow; i < startRow + p; i++) {
        for (unsigned j = startCol; j < startCol + q; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int getHighestSubmatrixSum(const int matrix[][MAX], unsigned rows, unsigned cols, unsigned p, unsigned q) {
    int maxSum = INT_MIN;
    for (unsigned i = 0; i <= rows - p; i++) {
        for (unsigned j = 0; j <= cols - q; j++) {
            int currentSum = getSubmatrixSum(matrix, p, q, i, j);
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }
    return maxSum;
}

int main() {
    unsigned rows, cols, p, q;
    cin >> rows >> cols;
    int matrix[MAX][MAX];
    readMatrix(matrix, rows, cols);
    cin >> p >> q;
    cout << getHighestSubmatrixSum(matrix, rows, cols, p, q);
    return 0;
}
