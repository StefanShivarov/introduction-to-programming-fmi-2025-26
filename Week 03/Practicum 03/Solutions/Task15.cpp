#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    unsigned n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int currentNum = i, sumOfDigits = 0;
        while (currentNum) {
            sumOfDigits += currentNum % 10;
            currentNum /= 10;
        }
        if (sumOfDigits % 2 == 0) {
            cout << i << " ";
        }
    }
}
