#include <iostream>
using namespace std;

void swapRows(double matrix[][100], int n, int rowA, int rowB) {
    double temp[100];
    for (int i = 0; i < n; i++)
        temp[i] = matrix[rowB][i];
    for (int i = 0; i < n; i++)
        matrix[rowB][i] = matrix[rowA][i];
    for (int i = 0; i < n; i++)
        matrix[rowA][i] = temp[i];
}
int positiveUnderK(double matrix[100][100], int n, int k) {
    for (int i = k + 1; i < n; i++)
        if (matrix[i][k] != 0)
            return i;
    return -1;
}
double detA(double matrix[100][100], int n) {
    double det = 1.;
    int sign = 1;
    for (int k = 0; k < n; k++) {
        if (matrix[k][k] == 0)
            if (positiveUnderK(matrix, n, k) != -1) {
                swapRows(matrix, n, k, positiveUnderK(matrix, n, k));
                sign = -sign;
            }
            else
                return 0;
        for (int i = k + 1; i < n; i++) {
            double factor = matrix[i][k] / matrix[k][k];
            for (int j = k; j < n; j++)
                matrix[i][j] -= factor * matrix[k][j];
        }
    }
    for (int i = 0; i < n; i++)
        det *= matrix[i][i];
    return sign * det;
}
int main() {
    double matrix[100][100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    cout << detA(matrix, n);
}