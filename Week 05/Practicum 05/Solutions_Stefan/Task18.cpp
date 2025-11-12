#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool isDivisibleByValue(int number, int divisor) {
    if (divisor == 0) {
        return false;
    }
    for (int i = 1; i * divisor <= number; i++) {
        if (i * divisor == number) {
            return true;
        }
    }
    return number == 0;
}

int main() {
    int number, divisor;
    cin >> number >> divisor;

    cout << isDivisibleByValue(number, divisor) << endl;
}