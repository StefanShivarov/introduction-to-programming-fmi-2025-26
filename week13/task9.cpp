#include <iostream>
using namespace std;

int gcd(const int a, const int b) {
    if (a == b) {
        return a;
    }
    if (a > b) {
        return gcd(a - b, b);
    }
        return gcd(a, b - a);
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
}