#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int getDivision(int number, int divisor) {
    if (divisor == 0) {
        cout << "Error! Cannot divide by 0!";
        return 0;
    }

    int result = 0;
    while (number >= divisor) {
        number -= divisor;
        result++;
    }
    return result;
}

int main() {
    int number, divisor;
    cin >> number >> divisor;
    cout << getDivision(number, divisor) << endl;
}