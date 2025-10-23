#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int num1 = 0;
    int num2 = 1;
    int l;
    cin >> l;
    int y = 0;
    if (l == 0) { cout << 0; }
    else if (l == 1) { cout << 1; }
    else if (l > 1)
    {
        for (int i = 0; i < l - 2; i++)
        {
            y = num2; num2 = num1 + num2; num1 = y;
        }
        cout << num2;
    }
    else {
        cout << "the number should be non-negative!" << endl; cin >> l;
    }
}