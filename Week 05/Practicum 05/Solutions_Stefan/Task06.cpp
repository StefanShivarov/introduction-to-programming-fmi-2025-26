#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned log_k(unsigned k, unsigned n) {
    unsigned result = 0, copyOfK = k;
    while (copyOfK <= n) {
        copyOfK *= k;
        result++;
    }
    return result;
}

int getDigitAtPosition(int number, unsigned position) {
    unsigned numLength = log_k(10, number) + 1;
    for (unsigned i = numLength; i > position; i--) {
        number /= 10;
    }
    return number % 10;
}

int main() {
    int num, pos;
    cin >> num >> pos;

    cout << getDigitAtPosition(num, pos) << endl;
}
