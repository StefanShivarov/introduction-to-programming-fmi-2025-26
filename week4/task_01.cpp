#include <iostream>
using namespace std;

double calculate(const int a, const int b, char action)
{
    switch (action)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b != 0)
            return (double)a / b; 
        else
        {
            cout << "error" << endl;
            return 0;
        }
    default:
        cout << "invalid" << endl;
        return 0;
    }
}

int main()
{
    int x, y;
    char op;
    cin >> x >> y >> op;
    cout << calculate(x, y, op) << endl;
    return 0;
}


