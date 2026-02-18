#include <iostream>
using namespace std;

int main() {
    int matrix[10][10];
    int n;
    cin >> n;
    int value = 1;
    int counter = n * n;
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
    while (value <= counter) {
        for (int j = left; j <= right; j++)
            matrix[top][j] = value++;
        top++;
        for (int i = top; i <= bottom; i++)
            matrix[i][right] = value++;
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                matrix[bottom][j] = value++;
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                matrix[i][left] = value++;
            left++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}