#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int e;
    cin >> e;
    for (int i = 0; i <= e; i++)
    {
        if (i == 0)
        {
            int j = 0;
            while (j < 2 * (e + 1) + 1)
            {
                if (j == (2 * (e + 1) + 1) / 2) { cout << '|'; j++; }
                else { cout << ' '; j++; }
            }
            cout << endl;
        }
        else
        {
            int j = 0;
            while (j < 2 * (e + 1) + 1)
            {
                if (j == (2 * (e + 1) + 1) / 2) { cout << '|'; j++; }
                else if (j == (2 * (e + 1) + 1) / 2 + 1 || j == (2 * (e + 1) + 1) / 2 - 1) { cout << ' '; j++; }
                else if (j < (e - i) || j >= (2 * (e + 1) + 1 - (e - i))) { cout << ' '; j++; }
                else { cout << '*'; j++; }
            }
            cout << endl;
        }
    }
}