#include <iostream>
using namespace std;

void printClockwise(int matrix[100][100], int n, int indentation) {
    int end = n - indentation - 1;
    for (int i = indentation; i < end; i++)
        cout << matrix[indentation][i] << " ";
    for (int i = indentation; i < end; i++)
        cout << matrix[i][n - indentation - 1] << " ";
    for (int i = end; i > indentation; i--)
        cout << matrix[n - indentation - 1][i] << " ";
    for (int i = end; i > indentation; i--)
        cout << matrix[i][indentation] << " ";
}
void printCounterClockwise(int matrix[100][100], int n, int indentation) {
    int end = n - indentation - 1;
    for (int i = end; i > indentation; i--)
        cout << matrix[indentation][i] << " ";
    for (int i = indentation; i < end; i++)
        cout << matrix[i][indentation] << " ";
    for (int i = indentation; i < end; i++)
        cout << matrix[n - indentation - 1][i] << " ";
    for (int i = end; i > indentation; i--)
        cout << matrix[i][n - indentation - 1] << " ";
}
int main() {
    int matrix[100][100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    for (int indentation = 0; indentation < (n + 1) / 2; indentation++) {
        int end = n - indentation - 1;
        if (end == indentation) {
            cout << matrix[indentation][indentation] << " ";
            break;
        }
        if (indentation % 2)
            printCounterClockwise(matrix, n, indentation);
        else
            printClockwise(matrix, n, indentation);
    }
}