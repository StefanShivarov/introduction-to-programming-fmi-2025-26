#include <iostream>
#include <math.h>
using namespace std;

void trasnferDigits(int& a, int& b, int k) {
    int x = 0;
    for (int i = 0; i < k; i++)
    {
        x += (a % 10) * (pow(10, i));
        a /= 10;
    }
    int g = b, j = 0;
    while (g > 0)
    {
        j++;
        g /= 10;
    }
    b += (x) * (pow(10, j));
}

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    trasnferDigits(a, b, k);
    cout << a << ' ' << b;
}