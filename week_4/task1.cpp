#include <iostream>
using namespace std;

int calculate(const int a, const int b, char c) {
    if (c == '+')
        return a + b;
    if (c == '-')
        return a - b;
    if (c == '*')
        return a * b;
    if (c == '/' && b != 0)
        return a / b;
    return 0;
}
int main() {
    int a, b;
    char c;
    cin >> a >> b >> c;
    cout << calculate(a, b, c);
}