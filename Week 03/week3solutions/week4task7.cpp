#include <iostream>
using namespace std;

int isNumber(int symbol) {
    if (symbol >= 48 && symbol <= 57) { return symbol-48; }
    else { return -1; }
}

int main()
{
    char z;
    cin >> z;
    cout << isNumber(z);
}