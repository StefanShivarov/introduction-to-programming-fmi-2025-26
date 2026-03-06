#include <iostream>
using namespace std;

int squareRootToLower(int n) {
    for (int i = 1; i <= n; i++) {
        if (i * i > n)
            return i - 1;
    }
    return 0;
}
int main() {
    int n;
    cin >> n;
    cout << squareRootToLower(n);
}