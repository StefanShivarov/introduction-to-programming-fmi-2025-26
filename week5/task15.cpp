#include <iostream>
using namespace std;

void reverseNum(int& n) {
    int numReversed = 0, counter = 0;
    while (n) {
        numReversed = numReversed * 10 + n % 10;
        n /= 10;
        counter++;
    }
    n = numReversed;
}
void numberMove(int& a, int& b, int k) {
    int move = 0;
    for (int i = 0; i < k; i++) {
        move = move * 10 + a % 10;
        a /= 10;
    }
    reverseNum(b);
    while (move) {
        b = b * 10 + move % 10;
        move /= 10;
    }
    reverseNum(b);
}
int main() {
    int a, b, k;
    cin >> a >> b >> k;
    numberMove(a, b, k);
    cout << "a = " << a << ", b = " << b << endl;
}