#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int a;
    int b;
    int x;
    cin >> a;
    cin >> b;
    cin >> x;
    if (x < a)
    {
        cout << 1;
    }
    else if (x == a)
    {
        cout << 2;
    }
    else if (x > a && x < b)
    {
        cout << 3;
    }
    else if (x == b)
    {
        cout << 4;
    }
    else if (x > b)
    {
        cout << 5;
    }
}
