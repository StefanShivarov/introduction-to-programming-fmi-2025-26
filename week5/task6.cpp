#include <iostream>
using namespace std;

int digitFromN(int number, unsigned int position) {
    int numReversed = 0, counter = 0, digitOfN = -1;
    while (number > 0) {
        numReversed = numReversed * 10 + number % 10;
        number /= 10;
        counter++;
    }
    if (position > counter)
        return 0;
    for (int i = 1; i <= position; i++) {
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