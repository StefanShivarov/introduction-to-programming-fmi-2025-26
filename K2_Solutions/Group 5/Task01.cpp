#include <iostream>
using namespace std;

const unsigned MAX = 9;

// this function both reads input to matrix and validates it
bool readSquareMatrix(int matrix[][MAX], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] < 1 || matrix[i][j] > 9) {
                cout << "Invalid element: " << matrix[i][j] << ", all matrix elements must be between 1 and 9!" << endl;
                return false;
            }
        }
    }
    return true;
}

int getRowSum(const int matrix[][MAX], unsigned size, unsigned rowIndex) {
    int sum = 0;
    for (unsigned i = 0; i < size; i++) {
        sum += matrix[rowIndex][i];
    }
    return sum;
}

int getColSum(const int matrix[][MAX], unsigned size, unsigned colIndex) {
    int sum = 0;
    for (unsigned i = 0; i < size; i++) {
        sum += matrix[i][colIndex];
    }
    return sum;
}

int getSubmatrixSum(const int matrix[][MAX], unsigned submatrixSize, unsigned startRow, unsigned startCol) {
    int sum = 0;
    for (unsigned i = startRow; i < startRow + submatrixSize; i++) {
        for (unsigned j = startCol; j < startCol + submatrixSize; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

bool areAllRowSumsEqual(const int matrix[][MAX], unsigned size) {
    int rowSum = getRowSum(matrix, size, 0);
    for (unsigned i = 1; i < size; i++) {
        if (rowSum != getRowSum(matrix, size, i)) {
            return false;
        }
    }
    return true;
}

bool areAllColSumsEqual(const int matrix[][MAX], unsigned size) {
    int colSum = getColSum(matrix, size, 0);
    for (unsigned i = 1; i < size; i++) {
        if (colSum != getColSum(matrix, size, i)) {
            return false;
        }
    }
    return true;
}

// in this case the submatrices shouldn't intersect each other, so we increment i and j with submatrixSize
bool areAllSubmatrixSumsEqual(const int matrix[][MAX], unsigned size, unsigned submatrixSize) {
    int submatrixSum = getSubmatrixSum(matrix, submatrixSize, 0, 0);
    for (unsigned i = 0; i <= size - submatrixSize; i += submatrixSize) {
        for (unsigned j = 0; j <= size - submatrixSize; j += submatrixSize) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (submatrixSum != getSubmatrixSum(matrix, submatrixSize, i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool areAllSumsEqual(const int matrix[][MAX], unsigned size, unsigned submatrixSize) {
    return areAllRowSumsEqual(matrix, size)
            && areAllColSumsEqual(matrix, size)
            && areAllSubmatrixSumsEqual(matrix, size, submatrixSize);
}

int squareRoot(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) {
            return i;
        }
    }
    return -1;
}

// this function fills a 9x9 matrix that should return true (sum of all rows, all cols, all submatrices are equal)
void fillMagic9x9(int matrix[][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matrix[i][j] = 0;
        }
    }
}

// this function fills a 9x9 matrix that should return false (sum of rows, cols, submatrices aren't all equal)
void fillNotMagic9x9(int matrix[][MAX]) {
    int counter = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matrix[i][j] = counter++;
        }
    }
}

int main() {
    // if you want to test it with 9x9 matrix and 3x3 submatrices exactly as in task description,
    // you can do this:

     const unsigned size = 9;
     const unsigned subSize = 3;

     int matrix[MAX][MAX];
     fillMagic9x9(matrix);
     // fillNotMagic9x9(matrix);
     cout << areAllSumsEqual(matrix, size, subSize);
     return 0;

    // -----------------
    // the following works for any matrix that is of size n = k^2 (you can test with a 4x4 matrix)
    /*

    unsigned n;
    cin >> n;
    
    int matrix[MAX][MAX];
    if (!readSquareMatrix(matrix, n)) {
        return 1; // exit code 1 on invalid input
    }
    
    int submatrixSize = squareRoot(n);
    if (submatrixSize == -1) {
        cout << "Matrix size must have a whole number as square root" << endl;
        return 1;
    }
    
    cout << areAllSumsEqual(matrix, n, submatrixSize);

    */
}
