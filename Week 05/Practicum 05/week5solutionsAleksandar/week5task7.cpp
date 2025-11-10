#include <iostream>
#include <cmath>
using namespace std;

int concat(unsigned int first, unsigned int second) {
    int digitsK = 0;
    int tempK = second;
    while (tempK > 0) {
        digitsK++;
        tempK /= 10;
    }
    int multi = 1;
    while (digitsK > 0) { multi *= 10; digitsK--; }
    second += first * multi;
    return second;
}
int main()
{
    int first, second;
    cin >> first >> second;
    cout << concat(first, second);
}