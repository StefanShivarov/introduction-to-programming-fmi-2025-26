#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int o;
    cin >> o;
    for (int i = 0; i < o; i++)
    {
        for (int j = 0; j < (2 * o) - 1; j++)
        {
            if (j == (((2 * o) - 1) / 2) || (j >= ((((2 * o) - 1)) / 2) - i) && (j <= ((((2 * o) - 1)) / 2) + i)) { cout << '*'; }
            else { cout << ' '; }
        }
        cout << endl;
    }
    for (int i = o - 1; i > 0; i--)
    {
        for (int j = 0; j < (2 * o) - 1; j++)
        {
            if (j == (((2 * o) - 1) / 2) || (j >= ((((2 * o) - 1)) / 2) - (i - 1)) && (j <= ((((2 * o) - 1)) / 2) + (i - 1))) { cout << '*'; }
            else { cout << ' '; }
        }
        cout << endl;
    }
}