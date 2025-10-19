#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a = 0;
    int b = 0;
    for (int i = 1; i <= n; i++)
    {
        a = i % 10;
        if (i > 9)
        {
            b = i / 10;
        }
        int sum = a + b;
        if (sum % 2 == 0)
        {
            cout << i << " ";
        }
    }
}
