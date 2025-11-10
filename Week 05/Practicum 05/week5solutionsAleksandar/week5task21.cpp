#include <iostream>
#include <cmath>
using namespace std;

void sqrt(int a) {
    int i = 1;
    while (i * i <= a)
    {
        i++;
    }
    cout << i - 1;
}

int main() {
    int a;
    cin >> a;
    sqrt(a);
}