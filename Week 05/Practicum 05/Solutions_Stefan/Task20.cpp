#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned log_k(unsigned k, unsigned n) {
    unsigned result = 0, copyOfK = k;
    while (copyOfK <= n) {
        copyOfK *= k;
        result++;
    }
    return result;
}

unsigned absoluteValue(int number) {
    return number < 0 ? -number : number;
}

unsigned closestPowerOfTwo(int number) {
    unsigned power = log_k(2, number);
    int result = 1;
    unsigned firstDiff = 0, secondDiff = 0;
    for (unsigned i = 1; i <= power + 1 ; i++) {
        result *= 2;
        if (i == power) {
            firstDiff = absoluteValue(result - number);
        }
    }
    secondDiff = absoluteValue(result - number);
    return firstDiff < secondDiff ? result / 2 : result;
}

int main() {
    int number;
    cin >> number;

    if (number > 100000) {
        cout << "Invalid number" << endl;
        return 1;
    }

    cout << closestPowerOfTwo(number) << endl;
}