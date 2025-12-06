#include <iostream>
using namespace std;

int main() {
    int matrix[50][50];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    int sum = 0;
    if (n % 2) {
        sum += matrix[n / 2][n / 2];
        matrix[n / 2][n / 2] = 0;
    }
    for (int i = 0; i < n; i++)
        sum += matrix[i][i] + matrix[i][n - i - 1];
    cout << sum;
}