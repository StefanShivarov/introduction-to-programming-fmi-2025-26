#include <iostream>

using std::cin;
using std::cout;

int sortDigits(int n) {
    int sortedNumber = 0;

    for (int digit = 0; digit <= 9; digit++) {
        int temp = n;

        while (temp > 0) {
            if (temp % 10 == digit) {
                sortedNumber *= 10;
                sortedNumber += digit;
            }
            temp /= 10;
        }
    }

    return sortedNumber;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << sortDigits(n);
}
