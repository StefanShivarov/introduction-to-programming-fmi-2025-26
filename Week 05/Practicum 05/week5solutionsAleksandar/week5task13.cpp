#include <iostream>
using namespace std;

void simplifyFraction(int& a, int& b) {
    int i = 2;
    while (i <= a)
    {
        if (a % i == 0 && b % i == 0) { a /= i; b /= i; i = 2; }
        else { i++; }
    }
}

int simplify(int& a, int& b, int (*operation)(int, int)) {
    simplifyFraction(a, b);
    return operation(a, b);
}
int main() {
    int a, b;
    cin >> a >> b;
    int result = simplify(a, b, [](int x, int y) { return x * y; });
    cout << a << ' ' << b << ' ' << result;
}