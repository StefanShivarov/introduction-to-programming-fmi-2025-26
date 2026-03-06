#include <iostream>
#include <cmath>
using namespace std;

void sort3(int& min, int& mid, int& max) {
    if (min > mid) swap(min, mid);
    if (mid > max) swap(mid, max);
    if (min > mid) swap(min, mid);
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    sort3(a, b, c);
    cout << "min = " << a << ", mid = " << b << ", max = " << c << endl;
}