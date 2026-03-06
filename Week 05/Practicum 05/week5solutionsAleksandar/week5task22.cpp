#include <iostream>
#include <cmath>
using namespace std;

void factorisation(int number) {
    for (int i = 2; i <= number; i++)
    {
        int k = 0;
        for (int j = 2; j <= i; j++)
        {
            if (i % j == 0)
            {
                k++;
            }
        }
        if (k == 1)
        {
            if (number % i == 0)
            {
                number /= i;
                cout << i << '.';
                i--;
            }
        }
    }
}

int main() {
    int x;
    cin >> x;
    factorisation(x);
}