#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_SIZE = 50;

void readMatrix(char matrix[][MAX_SIZE], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

bool areRowsPalindromic(const char matrix[][MAX_SIZE], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size / 2; j++) {
            if (matrix[i][j] != matrix[i][size - 1 - j]) {
                return false;
            }
        }
    }
    return true;
}

bool areColsPalindromic(const char matrix[][MAX_SIZE], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size / 2; j++) {
            if (matrix[j][i] != matrix[size - j - 1][i]) {
                return false;
            }
        }
    }
    return true;
}

bool areDiagonalsPalindromic(const char matrix[][MAX_SIZE], unsigned size) {
    for (unsigned i = 0; i < size / 2; i++) {
        if (matrix[i][i] != matrix[size - 1 - i][size - 1 - i]) {
            return false;
        }
    }

    for (unsigned i = 0; i < size / 2; i++) {
        if (matrix[i][size - 1 - i] != matrix[size - i - 1][i]) {
            return false;
        }
    }
    return true;
}

bool isPalindromeMatrix(const char matrix[][MAX_SIZE], unsigned size) {
    return areRowsPalindromic(matrix, size)
            && areColsPalindromic(matrix, size)
            && areDiagonalsPalindromic(matrix, size);
}

int main() {
    unsigned n;
    cin >> n;
    char matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, n);
    cout << (isPalindromeMatrix(matrix, n) ? "magic palindrome" : "not magic palindrome");
}
