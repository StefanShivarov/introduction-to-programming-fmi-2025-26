#include <iostream>
using namespace std;

int powerOfTwo(int y) {
    int x = 1;
    while (x * 2 <= y)
    {
        x *= 2;
    }
    int lower = x;
    int higher = x * 2;
    if (y - lower > higher - y) { return higher; }
    else { return lower; }
}

int main() {
    int a;
    cin >> a;
    cout << powerOfTwo(a);
}