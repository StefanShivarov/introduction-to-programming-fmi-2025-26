#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int year;
    cin >> year;
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            cout << "leap";
        }
        else
        {
            cout << ("not leap");
        }
    }
    else if (year % 4 == 0)
    {
        cout << "leap";
    }
    else
    {
        cout << "not leap";
    }
}
