#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool isDivisableByValue(int number, int divisor)
{
    double a = number;
    double aDivisor = divisor;
    if (a / aDivisor == number / divisor)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int number,divisor;
    cin >> number >> divisor;
    if (isDivisableByValue(number, divisor))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}

