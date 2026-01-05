#include <iostream>
using std::cin;
using std::cout;
using std::endl;

unsigned getDigitsCount(long num) {
    unsigned count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

void swap(int& a, int& b) {
    char temp = a;
    a = b;
    b = temp;
}

int* getDigits(long num, unsigned k, unsigned m) {
    unsigned size = getDigitsCount(num);
    int* result = new int[size];
    unsigned i = 0;
    while (num != 0) {
        result[size - i - 1] = num % 10;
        i++;
        num /= 10;
    }
    swap(result[k - 1], result[m - 1]);
    return result;
}

int main() {
    long num;
    unsigned k, m;
    cin >> num >> k >> m;

    int* digits = getDigits(num, k, m);
    unsigned size = getDigitsCount(num);

    for (unsigned i = 0; i < size; i++) {
        cout << digits[i] << ' ';
    }
    delete[] digits;
}
