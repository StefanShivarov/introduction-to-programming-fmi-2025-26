#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int n;
    cin >> n;

    int maxPower = 0;
    int temp = n;
    while (temp > 1) {
        temp /= 2;
        maxPower++;
    }

    bool first = true;
    temp = n;
    for (int i = maxPower; i >= 0; i--) {
        int val = 1;
        for (int j = 0; j < i; j++) {
            val *= 2;
        }

        if (temp >= val) {
            if (!first) {
                cout << " + ";
            }
            cout << "2^" << i;
            temp -= val;
            first = false;
        }
    }

}