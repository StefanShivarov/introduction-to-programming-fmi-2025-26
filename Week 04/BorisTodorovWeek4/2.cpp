#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int ascii(char symbol)
{
    return symbol;
}
int main()
{
    char c;
    cin >> c;
    cout<< ascii(c);
}
