#include <iostream>
#include <cmath>
using namespace std;

void swapNumberK(int a, int b, int k) {
    int x = a, y = b;

    int lenA = 0, lenB = 0;
    int tempA = a, tempB = b;
    while (tempA > 0) 
    { 
        lenA++; tempA /= 10;
    }
    while (tempB > 0) 
    { 
        lenB++; tempB /= 10;
    }
    int posA = lenA - k;
    int posB = lenB - k;
    int powerA = 1, powerB = 1;
    for (int i = 0; i < posA; i++) 
    { 
        powerA *= 10; 
    }
    for (int i = 0; i < posB; i++) 
    {
        powerB *= 10;
    }
    int digitA = (a / powerA) % 10;
    int digitB = (b / powerB) % 10;
    x = x - digitA * powerA + digitB * powerA;
    y = y - digitB * powerB + digitA * powerB;

    cout << x << " " << y;
}

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    swapNumberK(a, b, k);
}