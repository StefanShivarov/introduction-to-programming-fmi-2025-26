#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int squareRoot(unsigned number) {
    for (unsigned i = 0; i < number; i++) {
        if (i * i == number) {
            return i;
        }
        if (i * i > number) {
            return i - 1;
        }
    }
    return -1;
}

void printWhileDividingByDivisor(int& number, int divisor, bool& first) {
    while (number % divisor == 0) {
        if (!first) {
            cout << '.';
        }
        cout << divisor;
        first = false;
        number /= divisor;
    }
}

void primeFactorization(int number) {
    if (number < 2) {
        cout << number << endl;
        return;
    }

    bool first = true; // Flag to avoid printing "." before the first factor

    printWhileDividingByDivisor(number, 2, first);

    double sqrt = squareRoot(number);
    // Divide by odd numbers from 3 up to the square root
    for (int i = 3; i <= sqrt; i += 2) {
        printWhileDividingByDivisor(number, i, first);
    }

    // If number > 1, it is a prime factor itself
    if (number > 1) {
        if (!first) {
            cout << '.';
        }
        cout << number;
    }

    cout << endl;
}

int main() {
    int num;
    cin >> num;
    primeFactorization(num);
}
