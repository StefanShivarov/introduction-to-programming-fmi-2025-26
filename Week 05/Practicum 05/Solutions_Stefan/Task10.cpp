#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int lcm(int a, int b) {
    int greater = max(a, b);
    int smaller = min(a, b);

    for (int i = greater; i <= a * b; i += greater) {
        if (i % smaller == 0) {
            return i;
        }
    }
}

//Euclid's algorithm for gcd
int gcd(int a, int b) {
    if (b > a) {
        swap(a, b);
    }

    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int main() {
    int n;
    cin >> n;

    int first, second;
    cin >> first >> second;

    int greatestCommonDivisor = gcd(first, second);
    int leastCommonMultiple = lcm(first, second);

    for (int i = 2; i < n; i++) {
        int num;
        cin >> num;
        greatestCommonDivisor = gcd(greatestCommonDivisor, num);
        leastCommonMultiple = lcm(leastCommonMultiple, num);
    }

    cout << "GCD: " << greatestCommonDivisor << endl;
    cout << "LCM: " << leastCommonMultiple << endl;
}
