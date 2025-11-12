#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void sort3(int& min, int& mid, int& max) {
    if (min > max) {
        swap(min, max);
    }
    if (min > mid) {
        swap(min, mid);
    }
    if (mid > max) {
        swap(mid, max);
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    sort3(a, b, c);
    cout << "min: " << a << ", mid: " << b << ", max: " << c << endl;
}
