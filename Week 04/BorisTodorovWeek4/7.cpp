#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int checkIfNumber(char c)
{
    int asciiNumber = c;
    if (asciiNumber > 47 && asciiNumber < 58)
    {
        return asciiNumber-48;
    }
    else
    {
        return -1;
    }
}
int main()
{
    char c;
    cin >> c;
    cout << checkIfNumber(c);
}
