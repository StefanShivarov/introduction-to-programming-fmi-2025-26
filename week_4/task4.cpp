#include <iostream>
using namespace std;

bool isTriangle (int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (isTriangle(a, b, c))
            cout << a << " " << b << " " << c << endl;
    }
}