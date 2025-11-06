#include <iostream>

using std::cin;
using std::cout;

unsigned log_k(unsigned k, unsigned n) {
    unsigned result = 0, copyOfK = k;
    while (copyOfK <= n) {
        copyOfK *= k;
        result++;
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << log_k(k, n);
}
