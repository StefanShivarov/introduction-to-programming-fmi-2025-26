#include <iostream>
#include <cmath>
using namespace std;

int  getDigitOnPosition(int number, unsigned int position) {
    int digits = 0;
    int temp = number;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    for (int i = 0; i < digits - position; i++) {
        number /= 10;
    }
    return number % 10;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << getDigitOnPosition(n, k);
}