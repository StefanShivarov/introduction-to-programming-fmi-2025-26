#include <iostream>
#include <math.h>
using namespace std;

bool isDivisableByValue(int number, int divisor) {
    int y = (number / divisor)*divisor;
    return y==number;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << boolalpha << isDivisableByValue(a, b);

}