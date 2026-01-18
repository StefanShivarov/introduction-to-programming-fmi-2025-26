#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    a += b;
    b = a - b;
    a -= b;
}
int abs(int a) {
    return (a > 0) ? a : -a;
}
void rotateMatrix(int matrix[][100], int &n, int &m) {
    int rotatedMatrix[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            rotatedMatrix[j][n - i - 1] = matrix[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = rotatedMatrix[i][j];
    swap(n, m);//разменяме n и m, защото след завъртане на матрицата измеренията се разменят
}
int main() {
    int n, m;
    cin >> n >> m;
    int matrix[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    int deg;
    cin >> deg;
    if (deg % 360 == 0)
        deg = 0;
    else if (deg > 0)
        deg = deg / 90 % 4;
    else if (deg < 0)
        deg = 4 - abs(deg / 90 % 4);
    for (int i = 0; i < deg; i++)
        rotateMatrix(matrix, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}