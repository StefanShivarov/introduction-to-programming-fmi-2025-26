#include <iostream>
using namespace std;

bool checkIfAllAreEqual(int sums[22], int n) {
    for (int i = 1; i < n; i++)
        if (sums[i] != sums[0])
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
    int sums[22]; //Възможно най-много суми от редове, колони и диагонали за матрица n x n, n <= 10
    int sum = 0;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        sum = 0;
        ++pos;
        for (int j = 0; j < n; j++)
            sum += matrix[i][j];
        sums[pos] = sum;
    }
    for (int i = 0; i < n; i++) {
        sum = 0;
        ++pos;
        for (int j = 0; j < n; j++)
            sum += matrix[j][i];
        sums[pos] = sum;
    }
    ++pos;
    sum = 0;
    for (int i = 0; i < n; i++)
        sum += matrix[i][i];
    sums[pos] = sum;
    ++pos;
    sum = 0;
    for (int i = 0; i < n; i++)
        sum += matrix[i][n - i - 1];
    sums[pos] = sum;
    if (checkIfAllAreEqual(sums, 2 * n + 2))
        cout << "magic";
    else
        cout << "not magic";
}