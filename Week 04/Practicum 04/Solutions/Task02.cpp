#include <iostream>

using std::cin;
using std::cout;

unsigned ascii(char symbol) {
    return symbol;
}

int main() {
    char symbol;
    cin >> symbol;
    cout << ascii(symbol);
}
