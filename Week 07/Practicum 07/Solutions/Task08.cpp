#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_SIZE = 50;

void printOneToNSquareSpiral(unsigned n) {
    int matrix[n][n];
    int top = 0, left = 0, bottom = n - 1, right = n - 1, num = 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        for (int i = right; i >= left; i--) {
            matrix[bottom][i] = num++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            matrix[i][left] = num++;
        }
        left++;
    }

    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    unsigned n;
    cin >> n;
    printOneToNSquareSpiral(n);
}
