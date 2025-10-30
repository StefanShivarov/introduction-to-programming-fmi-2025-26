#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int f1 = 0;
    int f2 = 1;
    int n = 0;
    cin >> n;
    for (int i = 1;i < n;i++)
    {
        if (f1 < f2)
        {
            f1 += f2;
        }
        else
        {
            f2 += f1;
        }
    }
    if (f1 > f2)
    {
        cout << f2;
    }
    else
    {
        cout << f1;
    }

}