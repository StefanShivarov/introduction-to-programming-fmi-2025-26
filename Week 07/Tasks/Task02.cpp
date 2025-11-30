#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 50;

void printRow(const int matrix[][MAX_SIZE], unsigned size, unsigned rowIndex) {
    for (int i = 0; i < size; i++) {
        cout << matrix[rowIndex][i] << " ";
    }
}

void printRowReversed(const int matrix[][MAX_SIZE], unsigned size, unsigned rowIndex) {
    for (int i = size - 1; i >= 0; i--) {
        cout << matrix[rowIndex][i] << " ";
    }
}

void printMatrixRows(int matrix[][MAX_SIZE], unsigned size) {
    printRow(matrix, size, 0); // we print the first row before the loop

    unsigned top = 1, bottom = size - 1, counter = 0;
    // top is the index of the upmost row left to print
    // bottom is the index of the bottom-most row left to print

    /*
     * The idea is on every iteration (until top > bottom),
     * we print the bottom-most row and the top-most
     * to the left if counter % 2 == 0
     * or to the right if counter % 2 != 0
     */
    
    while (top <= bottom) {
        if (counter % 2 == 0) {
            printRowReversed(matrix, size, bottom);
            if (top != bottom) { // check if top is equal to bottom, so that we don't print the middle row twice
                printRowReversed(matrix, size, top);
            }
        } else {
            printRow(matrix, size, bottom);
            if (top != bottom) {
                printRow(matrix, size, top);
            }
        }

        top++;
        bottom--;
        counter++;
    }
}

void readSquareMatrix(int matrix[][MAX_SIZE], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

int main() {
    unsigned n;
    cin >> n;
    int matrix[MAX_SIZE][MAX_SIZE];
    readSquareMatrix(matrix, n);
    printMatrixRows(matrix, n);
}
