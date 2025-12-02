#include <iostream>
using namespace std;

int pow(int base, int power) {
    int result = 1;
    for (int i = 1; i <= power; i++)
        result *= base;
    return result;
}
int numLength(int n) {
    int counter = 0;
    while (n) {
        n /= 10;
        counter++;
    }
    return counter;
}
void reverseNum(int& n) {
    int numReversed = 0, counter = 0;
    while (n) {
        numReversed = numReversed * 10 + n % 10;
        n /= 10;
        counter++;
    }
    n = numReversed;
}
void digitFromN(int& number1, int& number2, int position) {
    reverseNum(number1);
    reverseNum(number2);
    int num1Remains = 0;
    int num2Remains = 0;
    int num1digit = 0;
    int num2digit = 0;
    for (int i = 1; i <= position; i++) {
        num1Remains = num1Remains * 10 + number1 % 10;
        number1 /= 10;
    }
    num1digit = num1Remains % 10;
    num1Remains /= 10;
    for (int i = 1; i <= position; i++) {
        num2Remains = num2Remains * 10 + number2 % 10;
        number2 /= 10;
    }
    num2digit = num2Remains % 10;
    num2Remains /= 10;
    number1 = number1 * 10 + num2digit;
    for (int i = 0; i < numLength(num1Remains); i++) {
        number1 = number1 * 10 + num1Remains % 10;
        num1Remains /= 10;
    }
    reverseNum(number1);
    number2 = number2 * 10 + num1digit;
    for (int i = 0; i < numLength(num2Remains); i++) {
        number2 = number2 * 10 + num2Remains % 10;
        num2Remains /= 10;
    }
    reverseNum(number2);
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    digitFromN(n, m, k);
    cout << n << " " << m;
}