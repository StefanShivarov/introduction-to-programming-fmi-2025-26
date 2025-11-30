#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_SIZE = 50;

void populateArrayWithDigits(unsigned number, int* arr, unsigned& size) {
    size = 0;
    while (number) {
        arr[size++] = number % 10;
        number /= 10;
    }
}

bool isPalindromic(const int* arr, unsigned size) {
    for (unsigned i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    unsigned num, numLength;
    cin >> num;
    int numArr[MAX_SIZE];
    populateArrayWithDigits(num, numArr, numLength);
    cout << (isPalindromic(numArr, numLength) ? "Yes" : "No");
}
