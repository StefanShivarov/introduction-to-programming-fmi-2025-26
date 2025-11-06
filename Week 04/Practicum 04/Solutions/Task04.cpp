#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool canFormTriangle(unsigned sideA, unsigned sideB, unsigned sideC) {
    return sideA + sideB > sideC
        && sideA + sideC > sideB
        && sideB + sideC > sideA;
}

int main() {
    int n;
    cin >> n;

    int a, b, c;
    while (n--) {
        cin >> a >> b >> c;
        if (canFormTriangle(a, b, c)) {
            cout << a << " " << b << " " << c << endl;
        }
    }
}
