#include <iostream>
using namespace std;

int digitFromN(int num, int digit) {
    int numReversed = 0, counter = 0, digitOfN = -1;
    while (num > 0) {
        numReversed = numReversed * 10 + num % 10;
        num /= 10;
        counter++;
    }
    if (digit > counter)
        return 0;
    for (int i = 1; i <= digit; i++) {
        digitOfN = numReversed % 10;
        numReversed /= 10;
    }
    return digitOfN;
}
int main() {
    int num, digit;
    cin >> num >> digit;
    cout << digitFromN(num, digit);
}