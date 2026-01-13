#include <iostream>
using namespace std;

int ascii(char symbol)
{
    return (int)symbol;
}

int main()
{
    char ch;
    cin >> ch;
    cout << ascii(ch) << endl;
    return 0;
}