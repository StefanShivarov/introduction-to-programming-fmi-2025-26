#include <iostream>
using std::cin;
using std::cout;
using std::endl;

char returnCapitalSymbol(char c)
{
    int asciiNumber = c;
    if (asciiNumber > 96 && asciiNumber < 123)
    {
        asciiNumber -= 32;
    }
    char capitalChar = asciiNumber;
    return capitalChar;
}
int main()
{
    char c;
    cin >> c;
    cout << returnCapitalSymbol(c);
}
