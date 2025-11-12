#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int gcd(int a, int b) {
    if (b > a) {
        swap(a, b);
    }

    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

unsigned simplify(unsigned& a, unsigned& b, unsigned (*func)(unsigned, unsigned)) {
    unsigned greatestCommonDivisor = gcd(a, b);
    a /= greatestCommonDivisor;
    b /= greatestCommonDivisor;
    return func(a, b);
}

int main() {
    unsigned a, b;
    cin >> a >> b;
    unsigned result = simplify(a, b, [](unsigned a, unsigned b) { return a + b; });
    cout << a << " " << b << " " << result << endl;
}
