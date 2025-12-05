#include <iostream>
using namespace std;

int manipulateNum(int num, int startPos, int n) {
    num >>= (startPos + 1);
    num &= ((1 << n) - 1);
    return num;
}

int main() {
    int num, startPos, n;
    cin >> num >> startPos >> n;

    cout << manipulateNum(num, startPos, n);
}