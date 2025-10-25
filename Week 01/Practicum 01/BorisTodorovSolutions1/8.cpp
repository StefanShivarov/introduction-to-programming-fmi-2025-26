#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    double a;
    char operation;
    double b;
    cin >> a;
    cin >> operation;
    cin >> b;
    if (operation == '+')
    {
        cout << a + b;
    }
    else if (operation == '-')
    {
        cout << a - b;
    }
    else if (operation == '*')
    {
        cout << a * b;
    }
    else if (operation == '/')
    {
        if (b == 0)
        {
            cout << "can't divide by zero";
        }
        else
        {
            cout << a / b;
        }
    }
}
