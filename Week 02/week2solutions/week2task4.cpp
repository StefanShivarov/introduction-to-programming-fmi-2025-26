#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int f;
    int i = 0;
    int sum1 = 0;
    while (i < 5)
    {
        cin >> f;
        if (f > 0) { i++; sum1 += f; }
    }
    cout << sum1;
}