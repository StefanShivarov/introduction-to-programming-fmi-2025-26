#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    a += b;
    b = a - b;
    a -= b;
}
void rotateMatrix(int matrix[10][10], int n) {
    int rotatedMatrix[10][10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            rotatedMatrix[j][n - i - 1] = matrix[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = rotatedMatrix[i][j];
}
bool isTriangleMatrix(int matrix[10][10], int n) {
    for (int j = 1; j < n; ++j) {
        int row = n - 1;
        int col = j;
        while (row >= 0 && col < n)
            if (matrix[row--][col++] > 0)
                return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    int matrix[10][10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    int results[4];
    results[0] = isTriangleMatrix(matrix, n);// разглеждаме четирите случая в които матрица е триъгълна
    rotateMatrix(matrix, n);
    results[1] = isTriangleMatrix(matrix, n);
    rotateMatrix(matrix, n);
    results[2] = isTriangleMatrix(matrix, n);
    rotateMatrix(matrix, n);
    results[3] = isTriangleMatrix(matrix, n);
    if (results[0] || results[1] || results[2] || results[3])
        cout << "true";
    else
        cout << "false";
}