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

unsigned pow(unsigned number, unsigned power) {
    unsigned result = 1;
    for (unsigned i = 0; i < power; i++) {
        result *= number;
    }
    return result;
}

void moveLastKDigits(unsigned& a, unsigned& b, unsigned k) {
    unsigned multiplier = pow(10, k);

    unsigned lastKDigitsOfA = a - (a / multiplier) * multiplier;
    a /= multiplier;

    unsigned bLength = log_k(10, b) + 1;
    multiplier = pow(10, bLength);
    lastKDigitsOfA *= multiplier;
    b += lastKDigitsOfA;
}

int main() {
    unsigned a, b, k;
    cin >> a >> b >> k;
    moveLastKDigits(a, b, k);
    cout << a << " " << b << endl;
}
