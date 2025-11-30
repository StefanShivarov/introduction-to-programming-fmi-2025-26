#include <iostream>
using namespace std;

const int MAX = 50;

void readMatrix(int matrix[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printClockwise(int matrix[][MAX], int &top, int &bottom, int &left, int &right) {
    // горен ред
    for (int j = left; j <= right; j++) {
        cout << matrix[top][j] << " ";
    }
    top++;

    // десен стълб
    for (int i = top; i <= bottom; i++) {
        cout << matrix[i][right] << " ";
    }
    right--;

    // долен ред
    for (int j = right; j >= left; j--) {
        cout << matrix[bottom][j] << " ";
    }
    bottom--;

    // ляв стълб
    for (int i = bottom; i >= top; i--) {
        cout << matrix[i][left] << " ";
    }
    left++;
}

void printAntiClockwise(int matrix[][MAX], int &top, int &bottom, int &left, int &right) {
    // горен ред (от десния ъгъл наляво)
    for (int j = right; j >= left; j--) {
        cout << matrix[top][j] << " ";
    }
    top++;

    // ляв стълб (от горе надолу)
    for (int i = top; i <= bottom; i++) {
        cout << matrix[i][left] << " ";
    }
    left++;

    // долен ред (отляво надясно)
    for (int j = left; j <= right; j++) {
        cout << matrix[bottom][j] << " ";
    }
    bottom--;

    // десен стълб (отдолу нагоре)
    for (int i = bottom; i >= top; i--) {
        cout << matrix[i][right] << " ";
    }
    right--;
}

void printLayeredSpiral(int matrix[][MAX], int n) {
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
    int layer = 0;

    while (top <= bottom && left <= right) {
        if (layer % 2 == 0) {
            printClockwise(matrix, top, bottom, left, right);
        } else {
            printAntiClockwise(matrix, top, bottom, left, right);
        }
        layer++;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int matrix[MAX][MAX];
    readMatrix(matrix, n);
    printLayeredSpiral(matrix, n);
    return 0;
}
