#include <iostream>
using namespace std;

int getBitsLength(int num) {
    int counter = 0;
    while (num) {
        num >>= 1;
        counter++;
    }
    return counter;
}

bool getKthBitFromLeftToRight(int num, int k) {
    return num & 1 << (getBitsLength(num) - k);
}

int main() {
    int num, pos;
    cin >> num >> pos;

    cout << getKthBitFromLeftToRight(num, pos);
}
