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

unsigned reverseNumber(unsigned num) {
    unsigned result = 0;
    while (num > 0) {
        result *= 10;
        result += num % 10;
        num /= 10;
    }
    return result;
}

void splitNumber(unsigned number, unsigned& firstHalf, unsigned& secondHalf) {
    firstHalf = secondHalf = 0;
    unsigned numLength = log_k(10, number) + 1;
    unsigned middle = numLength / 2 + numLength % 2;
    for (unsigned i = numLength; i > middle; i--) {
        secondHalf *= 10;
        secondHalf += number % 10;
        number /= 10;
    }
    for (unsigned i = middle; i >= 1; i--) {
        firstHalf *= 10;
        firstHalf += number % 10;
        number /= 10;
    }
    firstHalf = reverseNumber(firstHalf);
    secondHalf = reverseNumber(secondHalf);
}

int main() {
    unsigned num, firstHalf, secondHalf;
    cin >> num;
    splitNumber(num, firstHalf, secondHalf);
    cout << firstHalf << ' ' << secondHalf << endl;
}
