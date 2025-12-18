#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int powInt(int base, unsigned exp) {
    int result = 1;
    for (unsigned i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int binaryRowToDecimal(const bool* row, unsigned cols) {
    int num = 0;
    for (unsigned j = 0; j < cols; j++) {
        num += row[j] * powInt(2, cols - j - 1);
    }
    return num;
}

int* binaryMatrixToDecimalArr(const bool* const* binary, unsigned rows, unsigned cols) {
    if (!binary || rows == 0 || cols == 0) {
        return nullptr;
    }

    int* decimalArr = new int[rows];
    for (unsigned i = 0; i < rows; i++) {
        decimalArr[i] = binaryRowToDecimal(binary[i], cols);
    }
    return decimalArr;
}

int main() {
    unsigned rows, cols;
    cin >> rows >> cols;

    bool** binary = new bool*[rows];
    for (int i = 0; i < rows; i++) {
        binary[i] = new bool[cols];
        for (int j = 0; j < cols; j++) {
            cin >> binary[i][j];
        }
    }

    int* decimalArr = binaryMatrixToDecimalArr(binary, rows, cols);

    if (decimalArr) {
        for (unsigned i = 0; i < rows; ++i) {
            cout << decimalArr[i] << " ";
        }
        // free up allocated dynamic memory!!!
        delete[] decimalArr;
    }

    // free up allocated dynamic memory!!!
    for (unsigned i = 0; i < rows; ++i) {
        delete[] binary[i];
    }
    delete[] binary;
}
