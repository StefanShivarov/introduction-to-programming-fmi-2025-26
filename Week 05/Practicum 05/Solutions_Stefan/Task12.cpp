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

unsigned simplifyAndSum(unsigned& a, unsigned& b) {
    unsigned greatestCommonDivisor = gcd(a, b);
    a /= greatestCommonDivisor;
    b /= greatestCommonDivisor;
    return a + b;
}

int main() {
    unsigned a, b;
    cin >> a >> b;
    unsigned result = simplifyAndSum(a, b);
    cout << a << " " << b << " " << result << endl;
}
