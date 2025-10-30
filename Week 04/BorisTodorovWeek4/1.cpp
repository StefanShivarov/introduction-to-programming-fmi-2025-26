#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int calculate(const int a, const int b, char action)
{
    switch (action)
    {
    case ('+'):
        return a + b;
        break;
    case ('-'):
        return a - b;
        break;
    case ('*'):
        return a * b;
        break;
    case ('/'):
        return a / b;
        break;
    }

}
int main()
{
    int a, b;
    char c;
    cin >> a >> b>>c;
    cout<<calculate(a, b, c);
}
