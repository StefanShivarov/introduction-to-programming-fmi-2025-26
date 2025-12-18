#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int* binaryMatrixToDecimalArr(const bool* const* binary, unsigned rows, unsigned cols) {
    if (!binary || rows == 0 || cols == 0) {
        return nullptr;
    }

    int* decimalArr = new int[rows] {0};

    for (unsigned i = 0; i < rows; i++) {
        int num = 0; // this will store the decimal value of the current row
        for (unsigned j = 0; j < cols; j++) {
            // num << 1 :
            // shifts the current number one bit to the left

            //
            // | binary[i][j] :
            // sets the last bit to 0 or 1 based on what the digit is in the binary represenation

            // for example, if binary[i] is [0 1 0 1], we expect the number to be 5
            // first iteration the bits will look like this:
            // 00000000 = 00000000 | 00000000, so the last bit stays 0 => 00000000
            // second iteration:
            // 00000000 = 00000000 | 00000001, so the last bit is now 1 => 00000001
            // thid iteration:
            // 00000001 = 00000010 | 00000000 => 00000010
            // fourth iteration:
            // 00000010 = 00000100 | 00000001 => 00000101

            // at the end of the loop num will be 00000101, which is 5

            num = (num << 1) | binary[i][j];
        }
        decimalArr[i] = num;
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

    return 0;
}
