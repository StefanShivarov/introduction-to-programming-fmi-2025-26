#include <iostream>
using namespace std;

int ascii(char symbol) {
    return symbol;
}
int main() {
    char symbol;
    cin >> symbol;
    cout << ascii(symbol);
}