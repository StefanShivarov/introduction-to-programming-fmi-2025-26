#include <iostream>
#include <math.h>
using namespace std;

int simplifyAndSum(int& a, int& b) {
    int i = 2;
    while (i <= a)
    {
        if (a % i == 0 && b % i == 0) { a /= i; b /= i; i = 2; }
        else { i++; }
    }
    return a + b;
}

int main() {
    int a, b;
    cin >> a >> b;
    int result = simplifyAndSum(a, b);
    cout << a << ' ' << b << ' ' << result;
}