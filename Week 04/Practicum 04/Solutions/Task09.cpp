#include <iostream>

using std::cin;
using std::cout;

unsigned long long concat(unsigned first, unsigned second) {
    int secondCopy = second;
    while (secondCopy) {
        first *= 10;
        secondCopy /= 10;
    }
    return first + second;
}

int main() {
    unsigned first, second;
    cin >> first >> second;
    cout << concat(first, second);
}
