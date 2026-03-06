#include <iostream>
#include <cmath>
using namespace std;

void sortDigits(unsigned int number) {
    int num1 = number;
    int i = 1;
    while (i < 10)
    {
        while (number > 0)
        {
            if (number % 10 == i)
            {
                cout << i;
            }
            number /= 10;
        }
        number = num1;
        i++;
    }
}

int main() {
    int x;
    cin >> x;
    sortDigits(x);
}