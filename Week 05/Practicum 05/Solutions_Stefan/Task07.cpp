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

unsigned concat(unsigned a, unsigned b) {
    unsigned result = a;
    unsigned digitsCountOfB = log_k(10, b) + 1;
    for (unsigned i = 0; i < digitsCountOfB; i++) {
        result *= 10;
    }
    result += b;
    return result;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << concat(a, b) << endl;
}
