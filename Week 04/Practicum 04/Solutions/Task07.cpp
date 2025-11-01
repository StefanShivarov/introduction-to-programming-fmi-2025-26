#include <iostream>

using std::cin;
using std::cout;

bool isDigit(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

int symbolToNumber(char symbol) {
    return isDigit(symbol) ? symbol - '0' : -1;
}

int main() {
    char symbol;
    cin >> symbol;
    cout << symbolToNumber(symbol);
}
