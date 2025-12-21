#include <iostream>
using namespace std;

bool isDivisableByValue(int number, int divisor) {
    int remainder = number / divisor;
    return remainder * divisor == number;
}
int main() {
    int number, divisor;
    cin >> number >> divisor;
    if (isDivisableByValue(number, divisor))
        cout << "true";
    else
        cout << "false";
}