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

int main() {
    unsigned number;
    cin >> number;
    cout << squareRoot(number) << endl;
}
