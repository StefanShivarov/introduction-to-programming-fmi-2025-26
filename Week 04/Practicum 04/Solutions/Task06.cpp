#include <iostream>

using std::cin;
using std::cout;

const int ASCII_DIFFERENCE = 32;

bool isSmallLetter(char symbol) {
    return symbol >= 'a' && symbol <= 'z';
}

char convertToCapitalLetter(char symbol) {
    return symbol - ASCII_DIFFERENCE;
}

int main() {
    char symbol;
    cin >> symbol;

    if (!isSmallLetter(symbol)) {
        cout << "Error! Symbol is not a small letter!";
        return -1;
    }

    cout << convertToCapitalLetter(symbol);
}
