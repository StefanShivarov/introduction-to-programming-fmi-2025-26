#include <iostream>
using namespace std;

int recPow(const int base, const int power) {
    if (power < 0) {
        return -1;
    }
    if (power == 0) {
        return 1;
    }
    if (power == 1) {
        return base;
    }
    return base * recPow(base, power - 1);
}
int main() {
    int base, power;
    cin >> base >> power;
    cout << recPow(base, power);
}