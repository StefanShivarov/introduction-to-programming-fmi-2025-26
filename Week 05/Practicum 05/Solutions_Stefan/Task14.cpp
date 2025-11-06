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


void swapKthDigit(unsigned &a, unsigned &b, unsigned k) {
    unsigned aLength = log_k(10, a) + 1;
    unsigned bLength = log_k(10, b) + 1;

    if (aLength < k || bLength < k) {
        return;
    }

    unsigned aMultiplier = pow(10, aLength - k);
    unsigned bMultiplier = pow(10, bLength - k);

    unsigned kDigitA = (a / aMultiplier) % 10;
    unsigned kDigitB = (b / bMultiplier) % 10;

    unsigned removeFromA = kDigitA * aMultiplier;
    unsigned removeFromB = kDigitB * bMultiplier;

    unsigned addToA = kDigitB * aMultiplier;
    unsigned addToB = kDigitA * bMultiplier;

    a -= removeFromA;
    b -= removeFromB;
    a += addToA;
    b += addToB;
}

int main() {
    unsigned a, b, k;
    cin >> a >> b >> k;
    swapKthDigit(a, b, k);
    cout << a << " " << b << endl;
}
