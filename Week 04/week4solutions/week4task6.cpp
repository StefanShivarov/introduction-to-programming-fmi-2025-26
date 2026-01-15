#include <iostream>
using namespace std;

char Upper(char symbol) {
    if (symbol >= 97 && symbol <= 122) { symbol -= 32; }
    return symbol;
}

int main()
{
    char z;
    cin >> z;
    cout << Upper(z);
}