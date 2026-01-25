#include <iostream>
using namespace std;

int sumOfDigits(const int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumOfDigits(n - 1);
}
int main() {
    int n;
    cin >> n;
    cout << sumOfDigits(n);
}