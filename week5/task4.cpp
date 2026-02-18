#include <iostream>
using namespace std;

void absoluteValue(int& number) {
    if (number < 0)
        number *= -1;
}
int main() {
    int number;
    cin >> number;
    absoluteValue(number);
    cout << number << endl;
}