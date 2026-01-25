#include <iostream>
using namespace std;

bool isSymmetric(int matrix[10][10], int n) {
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (matrix[i][j] != matrix[j][i])
                return false;
    return true;
}
int main() {
    int matrix[10][10];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    if (isSymmetric(matrix, n))
        cout << "true";
    else
        cout << "false";
}