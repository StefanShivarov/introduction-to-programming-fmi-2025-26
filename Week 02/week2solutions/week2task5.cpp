#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int g;
    int i = 0;
    int min1 = 0;
    while (i < 3)
    {
        cin >> g;
        if (g < 0) { i++; if (g < min1) { min1 = g; } }
        else if (g >= 0) { i = 0; min1 = 0; }
    }
    cout << min1;
}