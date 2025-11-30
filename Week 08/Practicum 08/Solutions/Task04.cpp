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

void printSubmatrix(const int matrix[][MAX], unsigned p, unsigned q, unsigned startRow, unsigned startCol) {
    for (unsigned i = startRow; i < startRow + p; i++) {
        for (unsigned j = startCol; j < startCol + q; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printAllSubmatrices(const int matrix[][MAX], unsigned rows, unsigned cols, unsigned p, unsigned q) {
    for (unsigned i = 0; i <= rows - p; i++) {
        for (unsigned j = 0; j <= cols - q; j++) {
            printSubmatrix(matrix, p, q, i, j);
            cout << endl;
        }
    }
}

int main() {
    unsigned rows, cols, p, q;
    cin >> rows >> cols;
    int matrix[MAX][MAX];
    readMatrix(matrix, rows, cols);
    cin >> p >> q;
    printAllSubmatrices(matrix, rows, cols, p, q);
    return 0;
}
