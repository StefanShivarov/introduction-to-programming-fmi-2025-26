#include <iostream>

using std::cin;
using std::cout;

int getNumberLength(int number) {
    int length = 0;
    while (number) {
        length++;
        number /= 10;
    }
    return length;
}

int getDigitAtPosition(int num, int pos) {
    int length = getNumberLength(num);

    while (length - pos > 0) {
        num /= 10;
        length--;
    }

    // if the position is larger than the number's length, it returns the last digit
    return num % 10;
}

int main() {
    int num, pos;
    cin >> num >> pos;
    cout << getDigitAtPosition(num, pos);
}
