#include <iostream>
using namespace std;

const unsigned MAX = 10;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void readSquareMatrix(int matrix[][MAX], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printSquareMatrix(int matrix[][MAX], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void transpose(int matrix[][MAX], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = i + 1; j < size; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void rotate90DegToRight(int matrix[][MAX], unsigned size) {
    transpose(matrix, size);
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size / 2; j++) {
            swap(matrix[i][j], matrix[i][size - 1 - j]);
        }
    }
}

// alternative way to rotate a matrix 90 deg to the right:

// void rotate90DegToRight(int matrix[][MAX], unsigned size) {
//     int temp[MAX][MAX];
//     for (unsigned i = 0; i < size; i++) {
//         for (unsigned j = 0; j < size; j++) {
//             temp[j][size - 1 - i] = matrix[i][j];
//         }
//     }
//
//     for (unsigned i = 0; i < size; i++) {
//         for (unsigned j = 0; j < size; j++) {
//             matrix[i][j] = temp[i][j];
//         }
//     }
// }

void rotateMatrix(int matrix[][MAX], unsigned size, int times) {
    times %= 4; // 4x90 = 360 degrees, same position as start
    for (int i = 0; i < times; i++) {
        rotate90DegToRight(matrix, size);
    }
}

int main() {
    unsigned n;
    cin >> n;

    if (n > MAX) {
        cout << "N is too large!" << endl;
        return 1;
    }
    int matrix[MAX][MAX];
    readSquareMatrix(matrix, n);

    int m;
    cin >> m;
    if (m < 0) {
        cout << "Invalid input, M can't be a negative number!" << endl;
        return 1;
    }

    rotateMatrix(matrix, n, m);
    printSquareMatrix(matrix, n);
}
