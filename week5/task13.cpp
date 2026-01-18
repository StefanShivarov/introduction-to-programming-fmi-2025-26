#include <iostream>
using namespace std;

int gcd(int a, int b) {
    for (int i = a < b ? a : b; i >= 1; i--)
        if (a % i == 0 && b % i == 0)
            return i;
    return -1;
}
int simplifyAndSum(int &num, int &den) {
    int div = gcd(num, den);
    num /= div;
    den /= div;
    return num + den;
}
int main() {
    int a = 16, b = 20;
    int result = simplify(a, b, [](int x, int y){ return x * y; });//?
    cout << a << ' ' << b << ' ' << result;
}