#include <iostream>
using std::cin;
using std::cout;
using std::endl;

unsigned countDigits(unsigned n) {
    if (n == 0) { 
        return 1;
    }
    unsigned count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

unsigned findSmallestDigit(unsigned n) {
    unsigned smallest = 10;
    while (n > 0) {
        unsigned d = n % 10;
        if (d < smallest) {
            smallest = d;
        }
        n /= 10;
    }
    return smallest;
}

void removeOneDigit(unsigned &n, unsigned digit) {
    unsigned newNum = 0;
    unsigned multiplier = 1;
    bool removed = false;

    while (n > 0) {
        unsigned d = n % 10;
        if (!removed && d == digit) {
            removed = true; // пропускаме само едно срещане
        } else {
            newNum += d * multiplier;
            multiplier *= 10;
        }
        n /= 10;
    }
    n = newNum;
}

void appendDigit(unsigned &n, unsigned digit) {
    n = n * 10 + digit;
}

void sortDigits(unsigned &number) {
    if (number < 10) {
        return;
    }

    unsigned temp = number;
    unsigned sorted = 0;

    unsigned digits = countDigits(number);

    for (unsigned i = 0; i < digits; i++) {
        unsigned smallest = findSmallestDigit(number);
        appendDigit(sorted, smallest);
        removeOneDigit(number, smallest);
    }

    number = sorted;
}

int main() {
    unsigned num;
    cin >> num;
    sortDigits(num);
    cout << num << endl;
}
