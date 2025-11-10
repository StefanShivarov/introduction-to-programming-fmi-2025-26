#include <iostream>
#include <math.h>
using namespace std;

void splitNumber(int a, int n) {
    int left = 0, right = 0;
    for (int i = 0; i < n / 2; i++)
    {
        
        right += (a % 10)*(pow(10, i));
        a /= 10;
    }
    left = a;
    cout << "left = " << left << ", right = " << right;
}

int main() {
    int a, n = 0;
    cin >> a;
    int b = a;
    while (b > 0)
    {
        b /= 10;
        n++;
    }
    splitNumber(a, n);
}