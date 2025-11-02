#include <iostream>

using std::cin;
using std::cout;
using std::numeric_limits;

const double ERROR_VALUE = numeric_limits<double>().min(); // return value that suggests there might have been an error

double calculate(const int a, const int b, char action) {
    switch (action) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return b == 0 ? ERROR_VALUE : (double) a / b;
        default:
            return ERROR_VALUE;
    }
}

int main() {
    int a, b;
    char action;
    cin >> a >> b >> action;

    double result = calculate(a, b, action);

    result == ERROR_VALUE ? cout << "Error!" : cout << result;
}
