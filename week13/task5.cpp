#include <iostream>
using namespace std;

void printReverse(const int n) {
    if (n == 0) {
        return;
    }
    cout << n % 10;
    printReverse(n / 10);
}
int main() {
    int n;
    cin >> n;
    printReverse(n);
}