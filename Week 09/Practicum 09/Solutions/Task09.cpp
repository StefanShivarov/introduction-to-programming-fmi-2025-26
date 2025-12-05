#include <iostream>
using namespace std;

int toggleKthBit(int n, int k)
{
    return (n ^ (1 << k));
}

int main() {
    int num, pos;
    cin >> num >> pos;

    cout << toggleKthBit(num, pos);
}