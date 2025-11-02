#include <iostream>

using std::cin;
using std::cout;

int sumOfDigits(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int sumUntilOneDigit(int n) {
    while (n > 9) {
        n = sumOfDigits(n);
    }
    return n;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << sumUntilOneDigit(n);
}
