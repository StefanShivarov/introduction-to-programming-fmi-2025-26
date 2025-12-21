#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int power = 0;
    while (n > 0)
        if (pow(2, power) <= n)
            power++;
        else {
            power--;
            if (n - pow(2, power) != 0)
                cout << "2^" << power << " + ";
            else
                cout << "2^" << power;
            n = n - pow(2, power);
            power = 0;
        }
}