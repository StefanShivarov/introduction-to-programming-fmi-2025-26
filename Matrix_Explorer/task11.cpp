#include <iostream>
using namespace std;

int main() {
    int matrix[50][50];
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;
    while (top <= bottom && left <= right) {
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << matrix[i][right] << " ";
            right--;
        }
        for (int j = right; j >= left; j--)
            cout << matrix[top][j] << " ";
        top++;
        for (int i = top; i <= bottom; i++)
            cout << matrix[i][left] << " ";
        left++;
        if (top <= bottom) {
            for (int j = left; j <= right; j++)
                cout << matrix[bottom][j] << " ";
            bottom--;
        }
    }
}